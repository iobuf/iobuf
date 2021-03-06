# Feature Gates

| Feature gate                                | Description                                                                                                                |
| ------------------------------------------- | -------------------------------------------------------------------------------------------------------------------------- |
| Accelerators                                | Enables Nvidia GPU support when using Docker.                                                                              |
| AdvancedAuditing                            | Enables Advanced Audit.                                                                                                    |
| APIListChunking                             | Enables the API clients to retrieve LIST or GET resources from API server in chunks.                                       |
| APIResponseCompression                      | Enables the compression of API responses for LIST or GET requests.                                                         |
| AppArmor                                    | Enables AppArmor-based mandatory access control on Linux nodes when using Docker.                                          |
| BlockVolume                                 | Enables the definition and consumption of raw block devices in pods.                                                       |
| CPUManager                                  | Enables container-level CPU affinity support.                                                                              |
| CRIContainerLogRotation                     | Enables container log rotation for CRI container runtime.                                                                  |
| CSIPersistentVolume                         | Enables discovering and mounting volumes provisioned through a CSI (Container Storage Interface) compatible volume plugin. |
| CustomPodDNS                                | Enables customizing the DNS settings for a pod using the dnsConfig property.                                               |
| CustomResourceSubresources                  | Enables /status and /scale subresources on resources created from CustomResourceDefinition.                                |
| CustomResourceValidation                    | Enables schema-based validation on resources created from a custom resource definition.                                    |
| DebugContainers                             | Enables running a debugging container in a pod namespace to troubleshoot a running Pod.                                    |
| DevicePlugins                               | Enables device plug-in-based resource provisioning on nodes.                                                               |
| DynamicKubeletConfig                        | Enables the dynamic configuration in a cluster.                                                                            |
| DynamicVolumeProvisioning (deprecated)      | Enables the dynamic provisioning of persistent volumes to pods.                                                            |
| EnableEquivalenceClassCache                 | Enables the scheduler to cache equivalence of nodes when scheduling Pods.                                                  |
| ExperimentalCriticalPodAnnotation           | Enables annotating specific pods as critical so that their scheduling is guaranteed.                                       |
| ExperimentalHostUserNamespaceDefaultingGate | Enables the disabling of user namespaces. This is for containers that are using other host projects, host mounts,          |
|                                             | or containers that are privileged or using specific non-project capabilities, such as MKNODE, SYS_MODULE, and so forth.    |
|                                             | This should only be enabled if user project remapping is enabled in the Docker daemon.                                     |
| GCERegionalPersistentDisk                   | Enables the GCE Persistent Disk feature.                                                                                   |
| HugePages                                   | Enables the allocation and consumption of pre-allocated hugepages.                                                         |
| HyperVContainer                             | Enables Hyper-V isolation for Windows containers.                                                                          |
| Intializers                                 | Enables the dynamic admission control as an extension to the built-in admission controllers.                               |
| LocalStorageCapacityIsolation               | Enables the consumption of local ephemeral storage and the sizeLimit property of an emptyDir volume.                       |
| MountContainers                             | Enables using utility containers on the host as the volume mount.                                                          |
| MountPropagation                            | Enables sharing a volume mounted by one container to the other containers or pods.                                         |
| PersistentLocalVolumes                      | Enables the usage of local volume pods. Pod affinity has to be specified if requesting a local volume.                     |
| PodPriority                                 | Enables the descheduling and preemption of pods based on their priorities.                                                 |
| ReadOnlyAPIDataVolumes                      | Set secret, ConfigMap, DownwardAPI, and projected volumes to be mounted in read-only mode.                                 |
| RotateKubeletClientCertificate              | Enables the rotation of client TLS certificate on the cluster.                                                             |
| ResourceLimitsPriorityFunction              | Enables a scheduler priority function that assigns a lowest possible score of 1 to a node that satisfies at least one of   |
|                                             | the input pods CPU and memory limits. The intent is break ties between nodes with same scores.                             |
| RotateKubeletServerCertificate              | Enables the rotation of server TLS certificate on the cluster.                                                             |
| RunAsGroup                                  | Enables control over the primary group ID set on the init processes of containers.                                         |
| ScheduleDaemonSetPods                       | Enables DaemonSet pods to be scheduled by the default scheduler instead of the DaemonSet controller.                       |
| ServiceNodeExclusion                        | Enables the exclusion of nodes from load balancers created by a cloud provider.                                            |
| StorageObjectInUseProtection                | Enables postponing the deletion of persistent volume or persistent volume claim objects if they are still being used.      |
| StreamingProxyRedirects                     | Instructs the API server to intercept and follow redirects from the backend kubelet for streaming request.                 |
| SupportIPVSProxyMode                        | Enables providing in-cluster service load balancing using IP virtual servers.                                              |
| SupportPodPidsLimit                         | Enables support for limiting the number of processes (PIDs) running in a pod.                                              |
| TaintBasedEvictions                         | Enables evicting pods from nodes based on taints on nodes and tolerations on pods.                                         |
| TaintNodesByCondition                       | Enables automatic tainting nodes based on node conditions.                                                                 |
| TokenRequest                                | Enables the TokenRequest endpoint on service account resources.                                                            |
| VolumeScheduling                            | Enables volume-topology-aware scheduling and make the persistent volume claim (PVC) binding aware of scheduling decisions. |
|                                             | It also enables the usage of local volumes types when used together with the PersistentLocalVolumes feature gate.          |
