BuildConfig & DeploymentConfig
==============================

```text
                                +----------+               +-------------+
                                | Git repo |        +----->| ImageStream |
                                +----------+        |      +-------------+
                                      ^             |             ^
                                      |             |             |
    +---------------+          +-------------+      |     +------------------+       +------------------------+      +------+
    | Build trigger |--------->| BuildConfig |------+     | DeploymentConfig |------>| Replication Controller |----->| Pods |
    +---------------+          +-------------+            +------------------+       +------------------------+      +------+
                                      |       ^                              ^
                                      v        \                              \
                               +-------------+  \                              \
                               | Builder pod |   \| Clone Git repo, builds new  \| Watches for new images in ImageStream
                               +-------------+    | image from source, and adds  | and rolls out new version (similarly to
                                                  | it to the ImageStream        | a Deployment)
```
