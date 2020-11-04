#ifndef _NTKEAPI_H
#define _NTKEAPI_H

#if (NTLIB_CPU_MODE != NTLIB_KERNEL_MODE)
#define LOW_PRIORITY 0 
#define LOW_REALTIME_PRIORITY 16
#define HIGH_PRIORITY 31
#define MAXIMUM_PRIORITY 32
#endif

typedef enum _KTHREAD_STATE
{
    Initialized,
    Ready,
    Running,
    Standby,
    Terminated,
    Waiting,
    Transition,
    DeferredReady,
    GateWaitObsolete,
    WaitingForProcessInSwap,
    MaximumThreadState
} KTHREAD_STATE, *PKTHREAD_STATE;

typedef enum _KHETERO_CPU_POLICY
{
    KHeteroCpuPolicyAll,
    KHeteroCpuPolicyLarge,
    KHeteroCpuPolicyLargeOrIdle,
    KHeteroCpuPolicySmall,
    KHeteroCpuPolicySmallOrIdle,
    KHeteroCpuPolicyDynamic,
    KHeteroCpuPolicyStaticMax,
    KHeteroCpuPolicyBiasedSmall,
    KHeteroCpuPolicyBiasedLarge,
    KHeteroCpuPolicyDefault,
    KHeteroCpuPolicyMax
} KHETERO_CPU_POLICY, *PKHETERO_CPU_POLICY;

#if (NTLIB_CPU_MODE != NTLIB_KERNEL_MODE)

typedef enum _KWAIT_REASON
{
    Executive,
    FreePage,
    PageIn,
    PoolAllocation,
    DelayExecution,
    Suspended,
    UserRequest,
    WrExecutive,
    WrFreePage,
    WrPageIn,
    WrPoolAllocation,
    WrDelayExecution,
    WrSuspended,
    WrUserRequest,
    WrEventPair,
    WrQueue,
    WrLpcReceive,
    WrLpcReply,
    WrVirtualMemory,
    WrPageOut,
    WrRendezvous,
    WrKeyedEvent,
    WrTerminated,
    WrProcessInSwap,
    WrCpuRateControl,
    WrCalloutStack,
    WrKernel,
    WrResource,
    WrPushLock,
    WrMutex,
    WrQuantumEnd,
    WrDispatchInt,
    WrPreempted,
    WrYieldExecution,
    WrFastMutex,
    WrGuardedMutex,
    WrRundown,
    WrAlertByThreadId,
    WrDeferredPreempt,
    MaximumWaitReason
} KWAIT_REASON, *PKWAIT_REASON;

typedef enum _KPROFILE_SOURCE
{
    ProfileTime,
    ProfileAlignmentFixup,
    ProfileTotalIssues,
    ProfilePipelineDry,
    ProfileLoadInstructions,
    ProfilePipelineFrozen,
    ProfileBranchInstructions,
    ProfileTotalNonissues,
    ProfileDcacheMisses,
    ProfileIcacheMisses,
    ProfileCacheMisses,
    ProfileBranchMispredictions,
    ProfileStoreInstructions,
    ProfileFpInstructions,
    ProfileIntegerInstructions,
    Profile2Issue,
    Profile3Issue,
    Profile4Issue,
    ProfileSpecialInstructions,
    ProfileTotalCycles,
    ProfileIcacheIssues,
    ProfileDcacheAccesses,
    ProfileMemoryBarrierCycles,
    ProfileLoadLinkedIssues,
    ProfileMaximum
} KPROFILE_SOURCE;

#endif

#if (defined(PHNT_COMPILE) || NTLIB_CPU_MODE != NTLIB_KERNEL_MODE)

NATIVE_API(NTSTATUS, /*Nt*/CallbackReturn, (
    _In_reads_bytes_opt_(OutputLength) PVOID OutputBuffer,
    _In_ ULONG OutputLength,
    _In_ NTSTATUS Status
))

#if (defined(PHNT_COMPILE) || NTLIB_WIN_VERSION >= NTLIB_WIN_VISTA)
#endif

NATIVE_API(NTSTATUS, /*Nt*/QueryDebugFilterState, (
    _In_ ULONG ComponentId,
    _In_ ULONG Level
))

NATIVE_API(NTSTATUS, /*Nt*/SetDebugFilterState, (
    _In_ ULONG ComponentId,
    _In_ ULONG Level,
    _In_ BOOLEAN State
))

NATIVE_API(NTSTATUS, /*Nt*/YieldExecution, (
    VOID
))

#endif

#endif
