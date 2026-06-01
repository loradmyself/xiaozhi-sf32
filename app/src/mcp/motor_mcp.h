#ifndef MOTOR_MCP_H
#define MOTOR_MCP_H

#include "mcp_server.h"

class MotorTool {
public:
    static void RegisterMotorTool(McpServer* server);
};

#endif // MOTOR_MCP_H
