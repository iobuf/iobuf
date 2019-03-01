# Kubernetes Layers

+-------------------------------------------------------------+
|                       Ecosystem                             |
+-------------------------------------------------------------+
|       Interface Layer: Client Libraries and Tools           |
+-------------------------------------------------------------+
|   Governance Layer: Automation and Policy Enforcement       |
+-------------------------------------------------------------+
|        Application Layer: Deployment and Routing            |
+-------------------------------------------------------------+
|              Nucleus: API and Execution                     |
+-------------------------------------------------------------+
+---------+ +-------+ +------+ +--------+ +--------+ +--------+
|Container| |Network| |Volume| |Image   | |Cloud   | |Identity|
| Runtime | |Plugin | |Plugin| |Registry| |Provider| |Provider|
+---------+ +-------+ +------+ +--------+ +--------+ +--------+

# Core Packages

+-----------------------------------------------------------------------------------+
|  Interface Layer: Client Libraries Tools                                          |
| +-------+ +---------+ +------+ +----+ +-----------+ +----+ +----------+           |
| |kubectl| |client-go| |csharp| |java| |python-base| |ruby| |javascript|           |
| +-------+ +---------+ +------+ +----+ +-----------+ +----+ +----------+           |
+-----------------------------------------------------------------------------------+
+-----------------------------------------------------------------------------------+
| Governance Layer: Automation and Policy Enforcement (APIs optional and pluggable) |
| +---------------+ +-------------------+ +-------------+ +-----------+ +---------+ |
| |Service Catalog| |PodDisruptionBudget| |ResourceQuota| |PodTemplate| |PodPreset| |
| +---------------+ +-------------------+ +-------------+ +-----------+ +---------+ |
| +-------------------------+ +-------------+ +-------------------+ +----+          |
| |CertificateSigningRequest| |NetworkPolicy| |Controller Revision| |RBAC|          |
| +-------------------------+ +-------------+ +-------------------+ +----+          |
| +----------------------+ +-----------------------+ +----------+ +--------------+  |
| |VerticalPodAutoscaling| |HorizontalPodAutoscaler| |LimitRange| |ServiceAccount|  |
| +----------------------+ +-----------------------+ +----------+ +--------------+  |
| +-----------------+ +-----------+ +--------------------+                          |
| |PodSecurityPolicy| |ImageReview| |Dynamic Provisioning|                          |
| +-----------------+ +-----------+ +--------------------+                          |
+-----------------------------------------------------------------------------------+
+-----------------------------------------------------------------------------------+
| Application Layer: Deployment and Routing (APIs required and pluggable)           |
| +---+ +---------+ +----------+ +-----------+ +-------+ +----------------------+   |
| |DNS| |DaemonSet| |Deployment| |ReplicasSet| |Service| |Replication Controller|   |
| +---+ +---------+ +----------+ +-----------+ +-------+ +----------------------+   |
| +-------+ +-----------+ +-------+ +---+ +----------+ +------------------+         |
| |Ingress| |StatefulSet| |CronJob| |Job| |kube-proxy| |Ingress Controller|         |
| +-------+ +-----------+ +-------+ +---+ +----------+ +------------------+         |
+-----------------------------------------------------------------------------------+
+-----------------------------------------------------------------------------------+
| Nucleus: API and Execution (APIs required and not pluggable)                      |
| +----+ +---+ +---------+ +------------+ +-----------------------+                 |
| |Node| |api| |apiserver| |apimachinery| |apiextensions-apiserver|                 |
| +----+ +---+ +---------+ +------------+ +-----------------------+                 |
| +---------------+ +-------+ +---------+ +------+ +------------------+ +---+       |
| |kube-aggregator| |metrics| |Endpoints| |Events| |Cascading deletion| |Pod|       |
| +---------------+ +-------+ +---------+ +------+ +------------------+ +---+       |
| +---------+ +-------------------------------+ +--------------+ +-------------+    |
| |Namespace| |Persistent Valumes (and Claims)| |Authentication| |Authorization|    |
| +---------+ +-------------------------------+ +--------------+ +-------------+    |
| +---------+ +------+ +------------------+                                         |
| |ConfigMap| |Secret| |Persistence (etcd)|                                         |
| +---------+ +------+ +------------------+                                         |
+-----------------------------------------------------------------------------------+

# Core APIs

+-----------------------------------------------------------------------------------------------------------------------+
| Interface Layer: Client Libraries and Tools                                                                           |
|                                                             Note, client libraries and tools interact with core       |
|                                                             APIs rather Providing their own.                          |
+-----------------------------------------------------------------------------------------------------------------------+
+-----------------------------------------------------------------------------------------------------------------------+
| Governance Layer: Automation and Policy Enforcement (APIs optional and pluggable)                                     |
| +------------------------------------------------+ +----------------------------------------------------------------+ |
| |Automation                                      | |Policy                                                          | |
| |+------------------------+ +-------------------+| |+-------------+ +------------------+ +-------------------------+| |
| ||autoscaling/v1          | |policy/v1beta1     || ||core/v1      | |rbac/v1           | |certificates/v1beta1     || |
| ||HorizaontalPodAutoscaler| |PodDisruptionBudget|| ||LimitRange   | |ClusterRole       | |CertificateSigningRequest|| |
| |+------------------------+ +-------------------+| ||ResourceQuota| |ClusterRoleBinding| +-------------------------+| |
| |+-----------+ +-----------------+               | |+-------------+ |Role              | +------------------+       | |
| ||core/v1    | |settings/v1alpha1|               | |+-------------+ |RoleBinding       | |extensions/v1beta1|       | |
| ||PodTemplate| |PodPreset        |               | ||networking/v1| +------------------+ |PodSecurityPolicy |       | |
| |+-----------+ +-----------------+               | ||NetworkPolicy|                      +------------------+       | |
| +------------------------------------------------+ |+-------------+                                                 | |
|                                                    +----------------------------------------------------------------+ |
+-----------------------------------------------------------------------------------------------------------------------+
+-----------------------------------------------------------------------------------------------------------------------+
| Application Layer: Deployment and Routing (APIs required and pluggable)                                               |
| +----------------------------------------------------------+ +----------------------+                                 |
| | Workloads                                                | | Services             |                                 |
| | +--------+ +------------------+ +----------------------+ | | +-------+            |                                 |
| | |batch/v1| |apps/v1beta2      | |core/v1               | | | |core/v1|            |                                 |
| | |Job     | |ControllerRevision| |Replication Controller| | | |Service|            |                                 |
| | +--------+ |DaemonSet         | +----------------------+ | | +-------+            |                                 |
| |            |Deployment        | +-------------------+    | | +------------------+ |                                 |
| |            |ReplicaSet        | |scheduling/v1alpha1|    | | |extensions/v1beta1| |                                 |
| |            |StatefulSet       | |PriorityClass      |    | | |Ingress           | |                                 |
| |            +------------------+ +-------------------+    | | +------------------+ |                                 |
| | +--------------+                                         | +----------------------+                                 |
| | |batch/v2alpha1|                                         |                                                          |
| | |CronJob       |                                         |                                                          |
| | +--------------+                                         |                                                          |
| +----------------------------------------------------------+                                                          |
+-----------------------------------------------------------------------------------------------------------------------+
+-----------------------------------------------------------------------------------------------------------------------+
| Nucleus: API and Execution (APIs required and not pluggable)                                                          |
| +----------------------------------------------------------------+ +--------------------------------------+           |
| | API                                                            | | Execution                            |           |
| |+-----------------+        +---------+ +-----------------------+| |+---------------------+ +------------+|           |
| ||authentication/v1|        |core/v1  | |apiregistration/v1beta1|| ||core/v1              | |storage/v1  ||           |
| ||TokenReview      |        |Binding  | |APIService             || ||ComponentStatus      | |StorageClass||           |
| |+-----------------+        |Event    | +-----------------------+| ||ConfigMap            | +------------+|           |
| |+------------------------+ |Namespace| +------------------+     | ||Container            |               |           |
| ||authorization/v1        | +---------+ |extensions/v1beta1|     | ||Endpoints            |               |           |
| ||LocalSubjectAccessReview|             |ThirdPartyResource|     | ||Node                 |               |           |
| ||SelfSubjectAccessReview |             +------------------+     | ||PersistentVolume     |               |           |
| ||SubjectAccessReview     | +----------------------------------+ | ||PersistentVolumeClaim|               |           |
| |+------------------------+ |admissionregistration/v1alpha1    | | ||Pod                  |               |           |
| |+------------------------+ |ExternalAdmissionHookConfiguration| | ||Secret               |               |           |
| ||apiextensions/v1beta1   | |IntializerConfiguration           | | ||ServiceAccount       |               |           |
| ||CustomResourceDefinition| +----------------------------------+ | ||Volume               |               |           |
| |+------------------------+                                      | |+---------------------+               |           |
| +----------------------------------------------------------------+ +--------------------------------------+           |
+-----------------------------------------------------------------------------------------------------------------------+

# Conclusion

## Nucleus

- Minimum set of features and concepts needed to build the higher layers
- API
  - API machinery + persistence (etcd)
  - Auth[nz] + Admission control
  - Cascading deletion
  - Namespaces
  - Events
  - Add ons
- Execution
  - Node + Pod
  - Secret + ConfigMap
  - PV + PVC
  - Endpoints

## Application layer

- All users would use these to run applications
- Scheduling (pluggable)
- Enable major worload categories
  - Stateless: Deployment + ReplicaSet
  - Stateful: StatefulSet
  - Cluster: DaemonSet
  - Batch: CronJob + Job
- Enable services/microservices (pluggable)
  - Service + kube-proxy
  - Ingress + Ingress controller
  - DNS

## Governance layer

- Infrastructure / container / network metrics (for scheduling, scaling, etc.)
- Automation
  - Autoscaling: HorizontalPodAutoscaling, VerticalPodAutoscaling
  - PodDisruptionBudget
  - Dynamic provisioning of nodes, volumes, load balancers
  - PodPreset + Service Catalog
- Policy
  - RBAC
  - LimitRange
  - ResourceQuota
  - PodSecurityPolicy
  - ImageReview
  - NetworkPolicy

## Interface layer

- Client libraries
- Kubectl
- Swagger/OpenAPI-based tools
- Cluster federation

## Ecosystem

- Inside containers -- diverse workloads
- Above k8s -- diverse services and tools
  - Logging + Monitoring
  - Configuration DSLs + Deployment Orchestration
  - CI/CD + PaaS
  - Workflow + FaaS
  - Data processing
  - OTS applications: Middleware + Storage + Databases + ...
  - UIs + Mobile Apps + ChatOps + ...
- Below k8s -- diverse environments
  - Container runtimes + network plugins + volume plugins
  - Image registry
  - Cloud provider
  - Cluster + host creation, configuration, and management
  - Identity management