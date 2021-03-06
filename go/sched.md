# How does the golang scheduler works

Ian Lance Taylor & Dmitry Vyukov


I will give an overview of the scheduler used as of Go version 1.7.

There are three basic structures, known as G, M, and P. A G is a goroutine. An M
is an operating system thread. A P is a (logical) processor.

There are exactly GOMAXPROCS P’s (GOMAXPROCS is an environment variable and
runtime function that sets the amount of parallelism in the program). In order
for an M to execute a G, it must acquire a P. It will then run the G until it
stops. A G stops by making a system call such as an I/O operation, by blocking
on a channel operation, by calling a C function, by being preempted, or a few
other minor cases. A G can only be preempted at a safe point, which in the
current implementation can only happen when the code makes a function call.

When a G blocks in something like a channel operation, it will be placed on a
queue, and the M will look for another runnable G. If there are no runnable
G’s, the M will release the P and go to sleep.

When a G blocks in something like a system call, it will release the P and
remain running on the M. There is a system monitor thread that wakes up every so
often (between 20us and 10ms). If the system monitor thread sees that there
runnable G’s and available P’s, it will wake up a sleeping M, or start a new M
if there aren’t any sleeping. That M will acquire the P and pick up a runnable
G.

When a G completes a system call, it will have to re-acquire the P. If there are
no P’s available, it will be marked runnable and the M will go to sleep.

When a channel operation succeeds, it will wake up the other goroutine, mark it
as runnable, and, if there are available P’s, wake up an M to run it.

Although the garbage collector is mostly concurrent, there are a couple of
points where it has to briefly stop all the threads in order to safely move to
the next stage of collection. It does this by marking all the running goroutines
for preemption. As they reach a safe point, the G’s and the M’s will go to
sleep. When the garbage collector is the only remaining running G, it will move
to the next stage, and then wake up GOMAXPROC M’s, which will each find runnable
G’s, and keep going.

The runtime.Gosched function causes the M to put its current G on the list of
runnable goroutines and pick a new G off that list to start running.

I think that’s all the main points.


```text
┌─┐         ┌─┐         ┌─┐         ┌─┐                  ┌─┐
│ │         │ │         │ │         │ │                  │ │
├─┤         ├─┤         ├─┤         ├─┤                  ├─┤ Global
│ │         │G│         │ │         │ │                  │ │ state
├─┤         ├─┤         ├─┤         ├─┤                  ├─┤
│G│         │G│         │G│         │ │                  │G│
├─┤         ├─┤         ├─┤         ├─┤                  ├─┤
│G│         │G│         │G│         │G│                  │G│
└┬┘         └┬┘         └┬┘         └┬┘                  └─┘
 │           │           │           │
 ↓           ↓           ↓           ↓
┌─┬──────┐  ┌─┬──────┐  ┌─┬──────┐  ┌─┬──────┐     ┌────┐┌──────┐┌───────┐
│P│mcache│  │P│mcache│  │P│mcache│  │P│mcache│     │heap││timers││netpoll│
└┬┴──────┘  └┬┴──────┘  └┬┴──────┘  └┬┴──────┘     └────┘└──────┘└───────┘
 │           │           │           │
 ↓           ↓           ↓           ↓
┌─┐         ┌─┐         ┌─┐         ┌─┐               ┌─┐ ┌─┐ ┌─┐
│M│         │M│         │M│         │M│               │M│ │M│ │M│
└─┘         └─┘         └─┘         └─┘               └─┘ └─┘ └─┘
```

G - goroutine; P - logical processor; M - OS thread (machine)
