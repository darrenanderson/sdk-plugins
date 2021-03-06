/*
 * WARNING: this is an autogenerated file and will be overwritten by
 * the extension interface script.
 */

#include "s3eExt.h"
#include "IwDebug.h"
#include "s3eDevice.h"


#include "s3eMATSDK.h"

/**
 * Definitions for functions types passed to/from s3eExt interface
 */
typedef       void(*MATStartMobileAppTracker_t)(const char* adId, const char* adKey);
typedef       void(*MATSDKParameters_t)();
typedef       void(*MATTrackInstall_t)();
typedef       void(*MATTrackUpdate_t)();
typedef       void(*MATTrackInstallWithReferenceId_t)(const char* refId);
typedef       void(*MATTrackActionForEventIdOrName_t)(const char* eventIdOrName, bool isId, const char* refId);
typedef       void(*MATTrackActionForEventIdOrNameItems_t)(const char* eventIdOrName, bool isId, const MATArray* items, const char* refId, double revenueAmount, const char* currencyCode, uint8 transactionState);
typedef       void(*MATTrackAction_t)(const char* eventIdOrName, bool isId, double revenue, const char* currency);
typedef       void(*MATStartAppToAppTracking_t)(const char* targetAppId, const char* advertiserId, const char* offerId, const char* publisherId, bool shouldRedirect);
typedef       void(*MATSetPackageName_t)(const char* packageName);
typedef       void(*MATSetCurrencyCode_t)(const char* currencyCode);
typedef       void(*MATSetDeviceId_t)(const char* deviceId);
typedef       void(*MATSetOpenUDID_t)(const char* openUDID);
typedef       void(*MATSetUserId_t)(const char* userId);
typedef       void(*MATSetRevenue_t)(double revenue);
typedef       void(*MATSetSiteId_t)(const char* siteId);
typedef       void(*MATSetTRUSTeId_t)(const char* tpid);
typedef       void(*MATSetDelegate_t)(bool enable);
typedef       void(*MATSetUseHTTPS_t)(bool enable);
typedef       void(*MATSetAllowDuplicates_t)(bool allowDuplicates);
typedef       void(*MATSetShouldAutoGenerateMacAddress_t)(bool shouldAutoGenerate);
typedef       void(*MATSetShouldAutoGenerateODIN1Key_t)(bool shouldAutoGenerate);
typedef       void(*MATSetShouldAutoGenerateOpenUDIDKey_t)(bool shouldAutoGenerate);
typedef       void(*MATSetShouldAutoGenerateVendorIdentifier_t)(bool shouldAutoGenerate);
typedef       void(*MATSetShouldAutoGenerateAdvertiserIdentifier_t)(bool shouldAutoGenerate);
typedef       void(*MATSetUseCookieTracking_t)(bool useCookieTracking);
typedef       void(*MATSetRedirectUrl_t)(const char* redirectUrl);
typedef       void(*MATSetAdvertiserIdentifier_t)(const char* advertiserId);
typedef       void(*MATSetVendorIdentifier_t)(const char* vendorId);
typedef       void(*MATSetDebugResponse_t)(bool shouldDebug);

/**
 * struct that gets filled in by s3eMATSDKRegister
 */
typedef struct s3eMATSDKFuncs
{
    MATStartMobileAppTracker_t m_MATStartMobileAppTracker;
    MATSDKParameters_t m_MATSDKParameters;
    MATTrackInstall_t m_MATTrackInstall;
    MATTrackUpdate_t m_MATTrackUpdate;
    MATTrackInstallWithReferenceId_t m_MATTrackInstallWithReferenceId;
    MATTrackActionForEventIdOrName_t m_MATTrackActionForEventIdOrName;
    MATTrackActionForEventIdOrNameItems_t m_MATTrackActionForEventIdOrNameItems;
    MATTrackAction_t m_MATTrackAction;
    MATStartAppToAppTracking_t m_MATStartAppToAppTracking;
    MATSetPackageName_t m_MATSetPackageName;
    MATSetCurrencyCode_t m_MATSetCurrencyCode;
    MATSetDeviceId_t m_MATSetDeviceId;
    MATSetOpenUDID_t m_MATSetOpenUDID;
    MATSetUserId_t m_MATSetUserId;
    MATSetRevenue_t m_MATSetRevenue;
    MATSetSiteId_t m_MATSetSiteId;
    MATSetTRUSTeId_t m_MATSetTRUSTeId;
    MATSetDelegate_t m_MATSetDelegate;
    MATSetUseHTTPS_t m_MATSetUseHTTPS;
    MATSetAllowDuplicates_t m_MATSetAllowDuplicates;
    MATSetShouldAutoGenerateMacAddress_t m_MATSetShouldAutoGenerateMacAddress;
    MATSetShouldAutoGenerateODIN1Key_t m_MATSetShouldAutoGenerateODIN1Key;
    MATSetShouldAutoGenerateOpenUDIDKey_t m_MATSetShouldAutoGenerateOpenUDIDKey;
    MATSetShouldAutoGenerateVendorIdentifier_t m_MATSetShouldAutoGenerateVendorIdentifier;
    MATSetShouldAutoGenerateAdvertiserIdentifier_t m_MATSetShouldAutoGenerateAdvertiserIdentifier;
    MATSetUseCookieTracking_t m_MATSetUseCookieTracking;
    MATSetRedirectUrl_t m_MATSetRedirectUrl;
    MATSetAdvertiserIdentifier_t m_MATSetAdvertiserIdentifier;
    MATSetVendorIdentifier_t m_MATSetVendorIdentifier;
    MATSetDebugResponse_t m_MATSetDebugResponse;
} s3eMATSDKFuncs;

static s3eMATSDKFuncs g_Ext;
static bool g_GotExt = false;
static bool g_TriedExt = false;
static bool g_TriedNoMsgExt = false;

static bool _extLoad()
{
    if (!g_GotExt && !g_TriedExt)
    {
        s3eResult res = s3eExtGetHash(0xbb39d6f4, &g_Ext, sizeof(g_Ext));
        if (res == S3E_RESULT_SUCCESS)
            g_GotExt = true;
        else
            s3eDebugAssertShow(S3E_MESSAGE_CONTINUE_STOP_IGNORE,                 "error loading extension: s3eMATSDK");
            
        g_TriedExt = true;
        g_TriedNoMsgExt = true;
    }

    return g_GotExt;
}

static bool _extLoadNoMsg()
{
    if (!g_GotExt && !g_TriedNoMsgExt)
    {
        s3eResult res = s3eExtGetHash(0xbb39d6f4, &g_Ext, sizeof(g_Ext));
        if (res == S3E_RESULT_SUCCESS)
            g_GotExt = true;
        g_TriedNoMsgExt = true;
        if (g_TriedExt)
            g_TriedExt = true;
    }

    return g_GotExt;
}

s3eBool s3eMATSDKAvailable()
{
    _extLoadNoMsg();
    return g_GotExt ? S3E_TRUE : S3E_FALSE;
}

void MATStartMobileAppTracker(const char* adId, const char* adKey)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[0] func: MATStartMobileAppTracker"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_MATStartMobileAppTracker(adId, adKey);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void MATSDKParameters()
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[1] func: MATSDKParameters"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_MATSDKParameters();

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void MATTrackInstall()
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[2] func: MATTrackInstall"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_MATTrackInstall();

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void MATTrackUpdate()
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[3] func: MATTrackUpdate"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_MATTrackUpdate();

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void MATTrackInstallWithReferenceId(const char* refId)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[4] func: MATTrackInstallWithReferenceId"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_MATTrackInstallWithReferenceId(refId);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void MATTrackActionForEventIdOrName(const char* eventIdOrName, bool isId, const char* refId)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[5] func: MATTrackActionForEventIdOrName"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_MATTrackActionForEventIdOrName(eventIdOrName, isId, refId);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void MATTrackActionForEventIdOrNameItems(const char* eventIdOrName, bool isId, const MATArray* items, const char* refId, double revenueAmount, const char* currencyCode, uint8 transactionState)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[6] func: MATTrackActionForEventIdOrNameItems"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_MATTrackActionForEventIdOrNameItems(eventIdOrName, isId, items, refId, revenueAmount, currencyCode, transactionState);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void MATTrackAction(const char* eventIdOrName, bool isId, double revenue, const char* currency)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[7] func: MATTrackAction"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_MATTrackAction(eventIdOrName, isId, revenue, currency);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void MATStartAppToAppTracking(const char* targetAppId, const char* advertiserId, const char* offerId, const char* publisherId, bool shouldRedirect)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[8] func: MATStartAppToAppTracking"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_MATStartAppToAppTracking(targetAppId, advertiserId, offerId, publisherId, shouldRedirect);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void MATSetPackageName(const char* packageName)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[9] func: MATSetPackageName"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_MATSetPackageName(packageName);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void MATSetCurrencyCode(const char* currencyCode)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[10] func: MATSetCurrencyCode"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_MATSetCurrencyCode(currencyCode);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void MATSetDeviceId(const char* deviceId)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[11] func: MATSetDeviceId"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_MATSetDeviceId(deviceId);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void MATSetOpenUDID(const char* openUDID)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[12] func: MATSetOpenUDID"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_MATSetOpenUDID(openUDID);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void MATSetUserId(const char* userId)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[13] func: MATSetUserId"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_MATSetUserId(userId);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void MATSetRevenue(double revenue)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[14] func: MATSetRevenue"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_MATSetRevenue(revenue);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void MATSetSiteId(const char* siteId)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[15] func: MATSetSiteId"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_MATSetSiteId(siteId);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void MATSetTRUSTeId(const char* tpid)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[16] func: MATSetTRUSTeId"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_MATSetTRUSTeId(tpid);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void MATSetDelegate(bool enable)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[17] func: MATSetDelegate"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_MATSetDelegate(enable);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void MATSetUseHTTPS(bool enable)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[18] func: MATSetUseHTTPS"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_MATSetUseHTTPS(enable);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void MATSetAllowDuplicates(bool allowDuplicates)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[19] func: MATSetAllowDuplicates"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_MATSetAllowDuplicates(allowDuplicates);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void MATSetShouldAutoGenerateMacAddress(bool shouldAutoGenerate)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[20] func: MATSetShouldAutoGenerateMacAddress"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_MATSetShouldAutoGenerateMacAddress(shouldAutoGenerate);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void MATSetShouldAutoGenerateODIN1Key(bool shouldAutoGenerate)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[21] func: MATSetShouldAutoGenerateODIN1Key"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_MATSetShouldAutoGenerateODIN1Key(shouldAutoGenerate);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void MATSetShouldAutoGenerateOpenUDIDKey(bool shouldAutoGenerate)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[22] func: MATSetShouldAutoGenerateOpenUDIDKey"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_MATSetShouldAutoGenerateOpenUDIDKey(shouldAutoGenerate);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void MATSetShouldAutoGenerateVendorIdentifier(bool shouldAutoGenerate)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[23] func: MATSetShouldAutoGenerateVendorIdentifier"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_MATSetShouldAutoGenerateVendorIdentifier(shouldAutoGenerate);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void MATSetShouldAutoGenerateAdvertiserIdentifier(bool shouldAutoGenerate)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[24] func: MATSetShouldAutoGenerateAdvertiserIdentifier"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_MATSetShouldAutoGenerateAdvertiserIdentifier(shouldAutoGenerate);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void MATSetUseCookieTracking(bool useCookieTracking)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[25] func: MATSetUseCookieTracking"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_MATSetUseCookieTracking(useCookieTracking);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void MATSetRedirectUrl(const char* redirectUrl)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[26] func: MATSetRedirectUrl"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_MATSetRedirectUrl(redirectUrl);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void MATSetAdvertiserIdentifier(const char* advertiserId)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[27] func: MATSetAdvertiserIdentifier"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_MATSetAdvertiserIdentifier(advertiserId);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void MATSetVendorIdentifier(const char* vendorId)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[28] func: MATSetVendorIdentifier"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_MATSetVendorIdentifier(vendorId);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void MATSetDebugResponse(bool shouldDebug)
{
    IwTrace(MATSDK_VERBOSE, ("calling s3eMATSDK[29] func: MATSetDebugResponse"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_MATSetDebugResponse(shouldDebug);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}
