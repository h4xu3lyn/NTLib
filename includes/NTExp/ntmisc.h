#ifndef _NTMISC_H
#define _NTMISC_H

#define FLT_PORT_CONNECT 0x0001
#define FLT_PORT_ALL_ACCESS (FLT_PORT_CONNECT | STANDARD_RIGHTS_ALL)

typedef enum _VDMSERVICECLASS
{
    VdmStartExecution,
    VdmQueueInterrupt,
    VdmDelayInterrupt,
    VdmInitialize,
    VdmFeatures,
    VdmSetInt21Handler,
    VdmQueryDir,
    VdmPrinterDirectIoOpen,
    VdmPrinterDirectIoClose,
    VdmPrinterInitialize,
    VdmSetLdtEntries,
    VdmSetProcessLdtInfo,
    VdmAdlibEmulation,
    VdmPMCliControl,
    VdmQueryVdmProcess
} VDMSERVICECLASS, *PVDMSERVICECLASS;

NATIVE_API(NTSTATUS, /*Nt*/VdmControl, (
    _In_ VDMSERVICECLASS Service,
    _Inout_ PVOID ServiceData
))

NATIVE_API(NTSTATUS, /*Nt*/TraceEvent, (
    _In_ HANDLE TraceHandle,
    _In_ ULONG Flags,
    _In_ ULONG FieldSize,
    _In_ PVOID Fields
))

#if (defined(PHNT_COMPILE) || NTLIB_WIN_VERSION >= NTLIB_WIN_VISTA)
NATIVE_API(NTSTATUS, /*Nt*/TraceControl, (
    _In_ ULONG FunctionCode,
    _In_reads_bytes_opt_(InBufferLen) PVOID InBuffer,
    _In_ ULONG InBufferLen,
    _Out_writes_bytes_opt_(OutBufferLen) PVOID OutBuffer,
    _In_ ULONG OutBufferLen,
    _Out_ PULONG ReturnLength
))
#endif

#endif
