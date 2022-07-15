/*
 * Copyright (C) 2020 SSandbox project (https://github.com/SSandbox)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
 */

#pragma once

enum class Opcode : uint16
{
    MIN_OPCODE                       = 0x2000,
    MAX_OPCODE                       = 0x3FFF,

    SMSG_AUTH_RESPONSE               = 0x256D, // DF
    SMSG_AUTH_CHALLENGE              = 0x3048, // DF
    SMSG_ENABLE_ENCRYPTION           = 0x3049, // DF
    SMSG_RESUME_COMMS                = 0x304B, // DF
    SMSG_CONNECT_TO                  = 0x304D, // DF
    SMSG_FEATURE_STATUS_GLUE_SCREEN  = 0x25BE, // DF
    SMSG_ENUM_CHARACTERS_RESULT      = 0x2583, // DF

    SMSG_CREATE_CHAR                 = 0x26F7, // DF
    SMSG_DELETE_CHAR                 = 0x26F8, // DF
    SMSG_UPDATE_OBJECT               = 0x27BC, // DF
    SMSG_AVAILABLE_HOTFIXES          = 0x290F, // DF
    SMSG_UPDATE_TALENT_DATA          = 0x25D2, // DF
    SMSG_UPDATE_ACTION_BUTTONS       = 0x25DB, // DF
    SMSG_TUTORIAL_FLAGS              = 0x27AE, // DF
    SMSG_ACCOUNT_DATA_TIMES          = 0x2700, // DF
    SMSG_LOGOUT_COMPLETE             = 0x267E, // DF

    SMSG_QUERY_PLAYER_NAMES_RESPONSE = 0x301B, // DF
    SMSG_MOVE_TELEPORT               = 0x2E04, // DF
    SMSG_TRANSFER_PENDING            = 0x25CB, // DF
    SMSG_SUSPEND_TOKEN               = 0x25A8, // DF
    SMSG_RESUME_TOKEN                = 0x25A9, // DF

    SMSG_CHAT                        = 0x2BAD, // DF
    SMSG_SEND_KNOWN_SPELLS           = 0x2C2A, // DF
    SMSG_NEW_WORLD                   = 0x2598, // DF

    SMSG_MOVE_SET_CAN_FLY            = 0x2E05, // DF
    SMSG_MOVE_UNSET_CAN_FLY          = 0x2E06, // DF

    CMSG_AUTH_CONTINUED_SESSION      = 0x3766, // DF
    CMSG_AUTH_SESSION                = 0x3765, // DF
    CMSG_ENABLE_ENCRYPTION_ACK       = 0x3767, // DF
    CMSG_PING                        = 0x3768, // DF
    CMSG_LOG_DISCONNECT              = 0x3769, // DF
    CMSG_ENUM_CHARACTERS             = 0x35E8, // DF
    CMSG_PLAYER_LOGIN                = 0x35EA, // DF

    CMSG_CREATE_CHARACTER            = 0x3644, // DF
    CMSG_DELETE_CHARACTER            = 0x369B, // DF
    CMSG_QUERY_PLAYER_NAMES          = 0x3772, // DF

    CMSG_CHAT_MESSAGE_SAY            = 0x37E7, // DF

    CMSG_MOVE_HEARTBEAT              = 0x3A11, // DF
    CMSG_MOVE_STOP                   = 0x39E6, // DF

    CMSG_LOGOUT                      = 0x34E4, // DF
    CMSG_SUSPEND_TOKEN_RESPONSE      = 0x376A, // DF
    CMSG_WORLD_PORT_RESPONSE         = 0x35F9, // DF
};

namespace World
{
    enum class ConnectionType;
}

namespace Player
{
    class Session;
}

class Packet;

struct OpcodeInfo
{
    Opcode Opcode;
    char const* Name;
    void(Player::Session:: *Handler)(Packet const&);

    static bool IsValid(uint16 opcode);
    static bool IsValid(::Opcode opcode);
};

World::ConnectionType GetConnectionIndexForPacket(Opcode opcode);

OpcodeInfo const& GetOpcodeInfo(uint16 opcode);

inline OpcodeInfo const& GetOpcodeInfo(Opcode opcode)
{
    return GetOpcodeInfo(static_cast<uint16>(opcode));
}
