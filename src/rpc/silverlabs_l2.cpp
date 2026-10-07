#include <rpc/server.h>

#include <univalue.h>

static RPCHelpMan getl2info()
{
    return RPCHelpMan{
        "silverlabsl2_getinfo",
        "Returns status information for the experimental Silver Labs BTCS L2 test interface.\n",
        {},
        {
            RPCResult{
                RPCResult::Type::OBJ, "", "",
                {
                    {RPCResult::Type::STR, "name", "Interface name"},
                    {RPCResult::Type::STR, "status", "Current interface status"},
                    {RPCResult::Type::STR, "base_core", "BTCS core baseline"},
                    {RPCResult::Type::BOOL, "consensus_changes", "Whether this interface changes BTCS consensus"},
                    {RPCResult::Type::BOOL, "network_writes", "Whether this RPC performs network or chain writes"},
                }
            }
        },
        RPCExamples{
            HelpExampleCli("silverlabsl2_getinfo", "")
            + HelpExampleRpc("silverlabsl2_getinfo", "")
        },
        [&](const RPCHelpMan& self, const JSONRPCRequest& request) -> UniValue
        {
            UniValue result(UniValue::VOBJ);
            result.pushKV("name", "Silver Labs BTCS L2 Test Interface");
            result.pushKV("status", "experimental");
            result.pushKV("base_core", "31.1.3");
            result.pushKV("consensus_changes", false);
            result.pushKV("network_writes", false);
            return result;
        },
    };
}

void RegisterSilverLabsL2RPCCommands(CRPCTable& t)
{
    static const CRPCCommand commands[]{
        {"silverlabs_l2", &getl2info},
    };

    for (const auto& c : commands) {
        t.appendCommand(c.name, &c);
    }
}
