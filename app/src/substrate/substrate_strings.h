/*******************************************************************************
 *  (c) 2019 - 2024 Zondax AG
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 ********************************************************************************/
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

// Modules names
static const char* STR_MO_SYSTEM = "System";
static const char* STR_MO_UTILITY = "Utility";
static const char* STR_MO_MULTISIG = "Multisig";
static const char* STR_MO_PROXY = "Proxy";
static const char* STR_MO_BALANCES = "Balances";
static const char* STR_MO_VESTING = "Vesting";
static const char* STR_MO_DAPPSTAKING = "Dappstaking";
static const char* STR_MO_ASSETS = "Assets";
static const char* STR_MO_EVM = "Evm";
static const char* STR_MO_DAPPSTAKINGMIGRATION = "Dappstakingmigration";

// Methods names
static const char* STR_ME_REMARK = "Remark";
static const char* STR_ME_BATCH = "Batch";
static const char* STR_ME_BATCH_ALL = "Batch all";
static const char* STR_ME_FORCE_BATCH = "Force batch";
static const char* STR_ME_WITH_WEIGHT = "With weight";
static const char* STR_ME_AS_MULTI_THRESHOLD_1 = "As multi threshold 1";
static const char* STR_ME_AS_MULTI = "As multi";
static const char* STR_ME_APPROVE_AS_MULTI = "Approve as multi";
static const char* STR_ME_CANCEL_AS_MULTI = "Cancel as multi";
static const char* STR_ME_PROXY = "Proxy";
static const char* STR_ME_ADD_PROXY = "Add proxy";
static const char* STR_ME_REMOVE_PROXY = "Remove proxy";
static const char* STR_ME_REMOVE_PROXIES = "Remove proxies";
static const char* STR_ME_CREATE_PURE = "Create pure";
static const char* STR_ME_KILL_PURE = "Kill pure";
static const char* STR_ME_ANNOUNCE = "Announce";
static const char* STR_ME_REMOVE_ANNOUNCEMENT = "Remove announcement";
static const char* STR_ME_REJECT_ANNOUNCEMENT = "Reject announcement";
static const char* STR_ME_PROXY_ANNOUNCED = "Proxy announced";
static const char* STR_ME_TRANSFER_ALLOW_DEATH = "Transfer allow death";
static const char* STR_ME_SET_BALANCE_DEPRECATED = "Set balance deprecated";
static const char* STR_ME_FORCE_TRANSFER = "Force transfer";
static const char* STR_ME_TRANSFER_KEEP_ALIVE = "Transfer keep alive";
static const char* STR_ME_TRANSFER_ALL = "Transfer all";
static const char* STR_ME_FORCE_UNRESERVE = "Force unreserve";
static const char* STR_ME_UPGRADE_ACCOUNTS = "Upgrade accounts";
static const char* STR_ME_TRANSFER = "Transfer";
static const char* STR_ME_FORCE_SET_BALANCE = "Force set balance";
static const char* STR_ME_VEST = "Vest";
static const char* STR_ME_VEST_OTHER = "Vest other";
static const char* STR_ME_VESTED_TRANSFER = "Vested transfer";
static const char* STR_ME_FORCE_VESTED_TRANSFER = "Force vested transfer";
static const char* STR_ME_MERGE_SCHEDULES = "Merge schedules";
static const char* STR_ME_UNBOND_AND_UNSTAKE = "Unbond and unstake";
static const char* STR_ME_WITHDRAW_UNBONDED = "Withdraw Unbonded";
static const char* STR_ME_MAINTENANCE_MODE = "Maintenance mode";
static const char* STR_ME_REGISTER = "Register";
static const char* STR_ME_SET_DAPP_REWARD_BENEFICIARY = "Set dapp reward beneficiary";
static const char* STR_ME_SET_DAPP_OWNER = "Set dapp owner";
static const char* STR_ME_UNREGISTER = "Unregister";
static const char* STR_ME_LOCK = "Lock";
static const char* STR_ME_UNLOCK = "Unlock";
static const char* STR_ME_CLAIM_UNLOCKED = "Claim unlocked";
static const char* STR_ME_RELOCK_UNLOCKING = "Relock unlocking";
static const char* STR_ME_STAKE = "Stake";
static const char* STR_ME_UNSTAKE = "Unstake";
static const char* STR_ME_CLAIM_STAKER_REWARDS = "Claim staker rewards";
static const char* STR_ME_CLAIM_BONUS_REWARD = "Claim bonus reward";
static const char* STR_ME_CLAIM_DAPP_REWARD = "Claim dapp reward";
static const char* STR_ME_UNSTAKE_FROM_UNREGISTERED = "Unstake from unregistered";
static const char* STR_ME_CLEANUP_EXPIRED_ENTRIES = "Cleanup expired entries";
static const char* STR_ME_CREATE = "Create";
static const char* STR_ME_FORCE_CREATE = "Force create";
static const char* STR_ME_START_DESTROY = "Start destroy";
static const char* STR_ME_DESTROY_ACCOUNTS = "Destroy accounts";
static const char* STR_ME_DESTROY_APPROVALS = "Destroy approvals";
static const char* STR_ME_FINISH_DESTROY = "Finish destroy";
static const char* STR_ME_MINT = "Mint";
static const char* STR_ME_BURN = "Burn";
static const char* STR_ME_FREEZE = "Freeze";
static const char* STR_ME_THAW = "Thaw";
static const char* STR_ME_FREEZE_ASSET = "Freeze asset";
static const char* STR_ME_THAW_ASSET = "Thaw asset";
static const char* STR_ME_TRANSFER_OWNERSHIP = "Transfer ownership";
static const char* STR_ME_SET_TEAM = "Set team";
static const char* STR_ME_SET_METADATA = "Set metadata";
static const char* STR_ME_CLEAR_METADATA = "Clear metadata";
static const char* STR_ME_FORCE_SET_METADATA = "Force set metadata";
static const char* STR_ME_FORCE_CLEAR_METADATA = "Force clear metadata";
static const char* STR_ME_FORCE_ASSET_STATUS = "Force asset status";
static const char* STR_ME_APPROVE_TRANSFER = "Approve transfer";
static const char* STR_ME_CANCEL_APPROVAL = "Cancel approval";
static const char* STR_ME_FORCE_CANCEL_APPROVAL = "Force cancel approval";
static const char* STR_ME_TRANSFER_APPROVED = "Transfer approved";
static const char* STR_ME_TOUCH = "Touch";
static const char* STR_ME_REFUND = "Refund";
static const char* STR_ME_SET_MIN_BALANCE = "Set min balance";
static const char* STR_ME_TOUCH_OTHER = "Touch other";
static const char* STR_ME_REFUND_OTHER = "Refund other";
static const char* STR_ME_BLOCK = "Block";
static const char* STR_ME_WITHDRAW = "Withdraw";
static const char* STR_ME_MIGRATE = "Migrate";

// Items names
static const char* STR_IT_remark = "Remark";
static const char* STR_IT_pages = "Pages";
static const char* STR_IT_code = "Code";
static const char* STR_IT_items = "Items";
static const char* STR_IT_keys = "Keys";
static const char* STR_IT_prefix = "Prefix";
static const char* STR_IT_subkeys = "Subkeys";
static const char* STR_IT_calls = "Calls";
static const char* STR_IT_index = "Index";
static const char* STR_IT_call = "Call";
static const char* STR_IT_as_origin = "As origin";
static const char* STR_IT_weight = "Weight";
static const char* STR_IT_other_signatories = "Other signatories";
static const char* STR_IT_threshold = "Threshold";
static const char* STR_IT_maybe_timepoint = "Maybe timepoint";
static const char* STR_IT_max_weight = "Max weight";
static const char* STR_IT_call_hash = "Call hash";
static const char* STR_IT_timepoint = "Timepoint";
static const char* STR_IT_real = "Real";
static const char* STR_IT_force_proxy_type = "Force proxy type";
static const char* STR_IT_delegate = "Delegate";
static const char* STR_IT_proxy_type = "Proxy type";
static const char* STR_IT_delay = "Delay";
static const char* STR_IT_spawner = "Spawner";
static const char* STR_IT_height = "Height";
static const char* STR_IT_ext_index = "Ext index";
static const char* STR_IT_dest = "Dest";
static const char* STR_IT_amount = "Amount";
static const char* STR_IT_who = "Who";
static const char* STR_IT_new_free = "New free";
static const char* STR_IT_old_reserved = "Old reserved";
static const char* STR_IT_source = "Source";
static const char* STR_IT_keep_alive = "Keep alive";
static const char* STR_IT_target = "Target";
static const char* STR_IT_schedule = "Schedule";
static const char* STR_IT_schedule1_index = "Schedule1 index";
static const char* STR_IT_schedule2_index = "Schedule2 index";
static const char* STR_IT_contract_id = "Contract id";
static const char* STR_IT_enabled = "Enabled";
static const char* STR_IT_owner = "Owner";
static const char* STR_IT_smart_contract = "Smart contract";
static const char* STR_IT_beneficiary = "Beneficiary";
static const char* STR_IT_new_owner = "New owner";
static const char* STR_IT_era = "Era";
static const char* STR_IT_forcing_type = "Forcing type";
static const char* STR_IT_id = "Id";
static const char* STR_IT_admin = "Admin";
static const char* STR_IT_min_balance = "Min balance";
static const char* STR_IT_is_sufficient = "Is sufficient";
static const char* STR_IT_issuer = "Issuer";
static const char* STR_IT_freezer = "Freezer";
static const char* STR_IT_name = "Name";
static const char* STR_IT_symbol = "Symbol";
static const char* STR_IT_decimals = "Decimals";
static const char* STR_IT_is_frozen = "Is frozen";
static const char* STR_IT_destination = "Destination";
static const char* STR_IT_allow_burn = "Allow burn";
static const char* STR_IT_address = "Address";
static const char* STR_IT_input = "Input";
static const char* STR_IT_value = "Value";
static const char* STR_IT_gas_limit = "Gas limit";
static const char* STR_IT_max_fee_per_gas = "Max fee per gas";
static const char* STR_IT_max_priority_fee_per_gas = "Max priority fee per gas";
static const char* STR_IT_nonce = "Nonce";
static const char* STR_IT_access_list = "Access list";
static const char* STR_IT_init = "Init";
static const char* STR_IT_salt = "Salt";
static const char* STR_IT_weight_limit = "Weight limit";

#ifdef __cplusplus
}
#endif
