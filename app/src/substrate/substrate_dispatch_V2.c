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

#include "substrate_dispatch_V2.h"
#include "substrate_strings.h"
#include "zxmacros.h"
#include <stdint.h>
#ifdef LEDGER_SPECIFIC
#include "bolos_target.h"
#endif

__Z_INLINE parser_error_t _readMethod_utility_batch_V2(
    parser_context_t* c, pd_utility_batch_V2_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_batch_all_V2(
    parser_context_t* c, pd_utility_batch_all_V2_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_force_batch_V2(
    parser_context_t* c, pd_utility_force_batch_V2_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_allow_death_V2(
    parser_context_t* c, pd_balances_transfer_allow_death_V2_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_transfer_V2(
    parser_context_t* c, pd_balances_force_transfer_V2_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->source))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_keep_alive_V2(
    parser_context_t* c, pd_balances_transfer_keep_alive_V2_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_all_V2(
    parser_context_t* c, pd_balances_transfer_all_V2_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readbool(c, &m->keep_alive))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_V2(
    parser_context_t* c, pd_balances_transfer_V2_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_vest_V2(
    parser_context_t* c, pd_vesting_vest_V2_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_vest_other_V2(
    parser_context_t* c, pd_vesting_vest_other_V2_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->target))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_vested_transfer_V2(
    parser_context_t* c, pd_vesting_vested_transfer_V2_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->target))
    CHECK_ERROR(_readVestingInfo(c, &m->schedule))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_force_vested_transfer_V2(
    parser_context_t* c, pd_vesting_force_vested_transfer_V2_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->source))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->target))
    CHECK_ERROR(_readVestingInfo(c, &m->schedule))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_merge_schedules_V2(
    parser_context_t* c, pd_vesting_merge_schedules_V2_t* m)
{
    CHECK_ERROR(_readu32(c, &m->schedule1_index))
    CHECK_ERROR(_readu32(c, &m->schedule2_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_dappstaking_unbond_and_unstake_V2(
    parser_context_t* c, pd_dappstaking_unbond_and_unstake_V2_t* m)
{
    CHECK_ERROR(_readSmartContract(c, &m->contract_id))
    CHECK_ERROR(_readCompactu128(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_dappstaking_withdraw_unbonded_V2(
    parser_context_t* c, pd_dappstaking_withdraw_unbonded_V2_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_dappstaking_maintenance_mode_V2(
    parser_context_t* c, pd_dappstaking_maintenance_mode_V2_t* m)
{
    CHECK_ERROR(_readbool(c, &m->enabled))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_dappstaking_register_V2(
    parser_context_t* c, pd_dappstaking_register_V2_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->owner))
    CHECK_ERROR(_readSmartContract(c, &m->smart_contract))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_dappstaking_set_dapp_reward_beneficiary_V2(
    parser_context_t* c, pd_dappstaking_set_dapp_reward_beneficiary_V2_t* m)
{
    CHECK_ERROR(_readSmartContract(c, &m->smart_contract))
    CHECK_ERROR(_readOptionAccountId(c, &m->beneficiary))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_dappstaking_set_dapp_owner_V2(
    parser_context_t* c, pd_dappstaking_set_dapp_owner_V2_t* m)
{
    CHECK_ERROR(_readSmartContract(c, &m->smart_contract))
    CHECK_ERROR(_readAccountId(c, &m->new_owner))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_dappstaking_unregister_V2(
    parser_context_t* c, pd_dappstaking_unregister_V2_t* m)
{
    CHECK_ERROR(_readSmartContract(c, &m->smart_contract))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_dappstaking_lock_V2(
    parser_context_t* c, pd_dappstaking_lock_V2_t* m)
{
    CHECK_ERROR(_readCompactu128(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_dappstaking_unlock_V2(
    parser_context_t* c, pd_dappstaking_unlock_V2_t* m)
{
    CHECK_ERROR(_readCompactu128(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_dappstaking_claim_unlocked_V2(
    parser_context_t* c, pd_dappstaking_claim_unlocked_V2_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_dappstaking_relock_unlocking_V2(
    parser_context_t* c, pd_dappstaking_relock_unlocking_V2_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_dappstaking_stake_V2(
    parser_context_t* c, pd_dappstaking_stake_V2_t* m)
{
    CHECK_ERROR(_readSmartContract(c, &m->smart_contract))
    CHECK_ERROR(_readCompactu128(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_dappstaking_unstake_V2(
    parser_context_t* c, pd_dappstaking_unstake_V2_t* m)
{
    CHECK_ERROR(_readSmartContract(c, &m->smart_contract))
    CHECK_ERROR(_readCompactu128(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_dappstaking_claim_staker_rewards_V2(
    parser_context_t* c, pd_dappstaking_claim_staker_rewards_V2_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_dappstaking_claim_bonus_reward_V2(
    parser_context_t* c, pd_dappstaking_claim_bonus_reward_V2_t* m)
{
    CHECK_ERROR(_readSmartContract(c, &m->smart_contract))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_dappstaking_claim_dapp_reward_V2(
    parser_context_t* c, pd_dappstaking_claim_dapp_reward_V2_t* m)
{
    CHECK_ERROR(_readSmartContract(c, &m->smart_contract))
    CHECK_ERROR(_readCompactu32(c, &m->era))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_dappstaking_unstake_from_unregistered_V2(
    parser_context_t* c, pd_dappstaking_unstake_from_unregistered_V2_t* m)
{
    CHECK_ERROR(_readSmartContract(c, &m->smart_contract))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_dappstaking_cleanup_expired_entries_V2(
    parser_context_t* c, pd_dappstaking_cleanup_expired_entries_V2_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_evm_withdraw_V2(
    parser_context_t* c, pd_evm_withdraw_V2_t* m)
{
    CHECK_ERROR(_readH160(c, &m->address))
    CHECK_ERROR(_readBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_dappstakingmigration_migrate_V2(
    parser_context_t* c, pd_dappstakingmigration_migrate_V2_t* m)
{
    CHECK_ERROR(_readOptionWeight(c, &m->weight_limit))
    return parser_ok;
}

#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
__Z_INLINE parser_error_t _readMethod_system_remark_V2(
    parser_context_t* c, pd_system_remark_V2_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_with_weight_V2(
    parser_context_t* c, pd_utility_with_weight_V2_t* m)
{
    CHECK_ERROR(_readCall(c, &m->call))
    CHECK_ERROR(_readWeight(c, &m->weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_as_multi_threshold_1_V2(
    parser_context_t* c, pd_multisig_as_multi_threshold_1_V2_t* m)
{
    CHECK_ERROR(_readVecAccountId(c, &m->other_signatories))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_as_multi_V2(
    parser_context_t* c, pd_multisig_as_multi_V2_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId(c, &m->other_signatories))
    CHECK_ERROR(_readOptionTimepoint(c, &m->maybe_timepoint))
    CHECK_ERROR(_readCall(c, &m->call))
    CHECK_ERROR(_readWeight(c, &m->max_weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_approve_as_multi_V2(
    parser_context_t* c, pd_multisig_approve_as_multi_V2_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId(c, &m->other_signatories))
    CHECK_ERROR(_readOptionTimepoint(c, &m->maybe_timepoint))
    CHECK_ERROR(_readH256(c, &m->call_hash))
    CHECK_ERROR(_readWeight(c, &m->max_weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_cancel_as_multi_V2(
    parser_context_t* c, pd_multisig_cancel_as_multi_V2_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId(c, &m->other_signatories))
    CHECK_ERROR(_readTimepoint(c, &m->timepoint))
    CHECK_ERROR(_readH256(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_proxy_V2(
    parser_context_t* c, pd_proxy_proxy_V2_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->real))
    CHECK_ERROR(_readOptionProxyType(c, &m->force_proxy_type))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_add_proxy_V2(
    parser_context_t* c, pd_proxy_add_proxy_V2_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->delegate))
    CHECK_ERROR(_readProxyType(c, &m->proxy_type))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_remove_proxy_V2(
    parser_context_t* c, pd_proxy_remove_proxy_V2_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->delegate))
    CHECK_ERROR(_readProxyType(c, &m->proxy_type))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_remove_proxies_V2(
    parser_context_t* c, pd_proxy_remove_proxies_V2_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_create_pure_V2(
    parser_context_t* c, pd_proxy_create_pure_V2_t* m)
{
    CHECK_ERROR(_readProxyType(c, &m->proxy_type))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    CHECK_ERROR(_readu16(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_kill_pure_V2(
    parser_context_t* c, pd_proxy_kill_pure_V2_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->spawner))
    CHECK_ERROR(_readProxyType(c, &m->proxy_type))
    CHECK_ERROR(_readu16(c, &m->index))
    CHECK_ERROR(_readCompactu32(c, &m->height))
    CHECK_ERROR(_readCompactu32(c, &m->ext_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_announce_V2(
    parser_context_t* c, pd_proxy_announce_V2_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->real))
    CHECK_ERROR(_readCallHashOf(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_remove_announcement_V2(
    parser_context_t* c, pd_proxy_remove_announcement_V2_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->real))
    CHECK_ERROR(_readCallHashOf(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_reject_announcement_V2(
    parser_context_t* c, pd_proxy_reject_announcement_V2_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->delegate))
    CHECK_ERROR(_readCallHashOf(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_proxy_announced_V2(
    parser_context_t* c, pd_proxy_proxy_announced_V2_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->delegate))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->real))
    CHECK_ERROR(_readOptionProxyType(c, &m->force_proxy_type))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_set_balance_deprecated_V2(
    parser_context_t* c, pd_balances_set_balance_deprecated_V2_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    CHECK_ERROR(_readCompactBalance(c, &m->new_free))
    CHECK_ERROR(_readCompactBalance(c, &m->old_reserved))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_unreserve_V2(
    parser_context_t* c, pd_balances_force_unreserve_V2_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    CHECK_ERROR(_readBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_upgrade_accounts_V2(
    parser_context_t* c, pd_balances_upgrade_accounts_V2_t* m)
{
    CHECK_ERROR(_readVecAccountId(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_set_balance_V2(
    parser_context_t* c, pd_balances_force_set_balance_V2_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    CHECK_ERROR(_readCompactBalance(c, &m->new_free))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_create_V2(
    parser_context_t* c, pd_assets_create_V2_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->admin))
    CHECK_ERROR(_readBalance(c, &m->min_balance))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_force_create_V2(
    parser_context_t* c, pd_assets_force_create_V2_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->owner))
    CHECK_ERROR(_readbool(c, &m->is_sufficient))
    CHECK_ERROR(_readCompactBalance(c, &m->min_balance))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_start_destroy_V2(
    parser_context_t* c, pd_assets_start_destroy_V2_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_destroy_accounts_V2(
    parser_context_t* c, pd_assets_destroy_accounts_V2_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_destroy_approvals_V2(
    parser_context_t* c, pd_assets_destroy_approvals_V2_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_finish_destroy_V2(
    parser_context_t* c, pd_assets_finish_destroy_V2_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_mint_V2(
    parser_context_t* c, pd_assets_mint_V2_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->beneficiary))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_burn_V2(
    parser_context_t* c, pd_assets_burn_V2_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_transfer_V2(
    parser_context_t* c, pd_assets_transfer_V2_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->target))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_transfer_keep_alive_V2(
    parser_context_t* c, pd_assets_transfer_keep_alive_V2_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->target))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_force_transfer_V2(
    parser_context_t* c, pd_assets_force_transfer_V2_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->source))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_freeze_V2(
    parser_context_t* c, pd_assets_freeze_V2_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_thaw_V2(
    parser_context_t* c, pd_assets_thaw_V2_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_freeze_asset_V2(
    parser_context_t* c, pd_assets_freeze_asset_V2_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_thaw_asset_V2(
    parser_context_t* c, pd_assets_thaw_asset_V2_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_transfer_ownership_V2(
    parser_context_t* c, pd_assets_transfer_ownership_V2_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->owner))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_set_team_V2(
    parser_context_t* c, pd_assets_set_team_V2_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->issuer))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->admin))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->freezer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_set_metadata_V2(
    parser_context_t* c, pd_assets_set_metadata_V2_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->id))
    CHECK_ERROR(_readVecu8(c, &m->name))
    CHECK_ERROR(_readVecu8(c, &m->symbol))
    CHECK_ERROR(_readu8(c, &m->decimals))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_clear_metadata_V2(
    parser_context_t* c, pd_assets_clear_metadata_V2_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_force_set_metadata_V2(
    parser_context_t* c, pd_assets_force_set_metadata_V2_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->id))
    CHECK_ERROR(_readVecu8(c, &m->name))
    CHECK_ERROR(_readVecu8(c, &m->symbol))
    CHECK_ERROR(_readu8(c, &m->decimals))
    CHECK_ERROR(_readbool(c, &m->is_frozen))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_force_clear_metadata_V2(
    parser_context_t* c, pd_assets_force_clear_metadata_V2_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_force_asset_status_V2(
    parser_context_t* c, pd_assets_force_asset_status_V2_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->owner))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->issuer))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->admin))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->freezer))
    CHECK_ERROR(_readCompactBalance(c, &m->min_balance))
    CHECK_ERROR(_readbool(c, &m->is_sufficient))
    CHECK_ERROR(_readbool(c, &m->is_frozen))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_approve_transfer_V2(
    parser_context_t* c, pd_assets_approve_transfer_V2_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->delegate))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_cancel_approval_V2(
    parser_context_t* c, pd_assets_cancel_approval_V2_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->delegate))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_force_cancel_approval_V2(
    parser_context_t* c, pd_assets_force_cancel_approval_V2_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->owner))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->delegate))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_transfer_approved_V2(
    parser_context_t* c, pd_assets_transfer_approved_V2_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->owner))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->destination))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_touch_V2(
    parser_context_t* c, pd_assets_touch_V2_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_refund_V2(
    parser_context_t* c, pd_assets_refund_V2_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->id))
    CHECK_ERROR(_readbool(c, &m->allow_burn))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_set_min_balance_V2(
    parser_context_t* c, pd_assets_set_min_balance_V2_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->id))
    CHECK_ERROR(_readBalance(c, &m->min_balance))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_touch_other_V2(
    parser_context_t* c, pd_assets_touch_other_V2_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_refund_other_V2(
    parser_context_t* c, pd_assets_refund_other_V2_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_assets_block_V2(
    parser_context_t* c, pd_assets_block_V2_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->id))
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
    return parser_ok;
}

#endif

parser_error_t _readMethod_V2(
    parser_context_t* c,
    uint8_t moduleIdx,
    uint8_t callIdx,
    pd_Method_V2_t* method)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {

    case 2816: /* module 11 call 0 */
        CHECK_ERROR(_readMethod_utility_batch_V2(c, &method->basic.utility_batch_V2))
        break;
    case 2818: /* module 11 call 2 */
        CHECK_ERROR(_readMethod_utility_batch_all_V2(c, &method->basic.utility_batch_all_V2))
        break;
    case 2820: /* module 11 call 4 */
        CHECK_ERROR(_readMethod_utility_force_batch_V2(c, &method->basic.utility_force_batch_V2))
        break;
    case 7936: /* module 31 call 0 */
        CHECK_ERROR(_readMethod_balances_transfer_allow_death_V2(c, &method->nested.balances_transfer_allow_death_V2))
        break;
    case 7938: /* module 31 call 2 */
        CHECK_ERROR(_readMethod_balances_force_transfer_V2(c, &method->nested.balances_force_transfer_V2))
        break;
    case 7939: /* module 31 call 3 */
        CHECK_ERROR(_readMethod_balances_transfer_keep_alive_V2(c, &method->nested.balances_transfer_keep_alive_V2))
        break;
    case 7940: /* module 31 call 4 */
        CHECK_ERROR(_readMethod_balances_transfer_all_V2(c, &method->nested.balances_transfer_all_V2))
        break;
    case 7943: /* module 31 call 7 */
        CHECK_ERROR(_readMethod_balances_transfer_V2(c, &method->nested.balances_transfer_V2))
        break;
    case 8192: /* module 32 call 0 */
        CHECK_ERROR(_readMethod_vesting_vest_V2(c, &method->nested.vesting_vest_V2))
        break;
    case 8193: /* module 32 call 1 */
        CHECK_ERROR(_readMethod_vesting_vest_other_V2(c, &method->nested.vesting_vest_other_V2))
        break;
    case 8194: /* module 32 call 2 */
        CHECK_ERROR(_readMethod_vesting_vested_transfer_V2(c, &method->nested.vesting_vested_transfer_V2))
        break;
    case 8195: /* module 32 call 3 */
        CHECK_ERROR(_readMethod_vesting_force_vested_transfer_V2(c, &method->nested.vesting_force_vested_transfer_V2))
        break;
    case 8196: /* module 32 call 4 */
        CHECK_ERROR(_readMethod_vesting_merge_schedules_V2(c, &method->nested.vesting_merge_schedules_V2))
        break;
    case 8708: /* module 34 call 4 */
        CHECK_ERROR(_readMethod_dappstaking_unbond_and_unstake_V2(c, &method->nested.dappstaking_unbond_and_unstake_V2))
        break;
    case 8709: /* module 34 call 5 */
        CHECK_ERROR(_readMethod_dappstaking_withdraw_unbonded_V2(c, &method->nested.dappstaking_withdraw_unbonded_V2))
        break;
    case 8704: /* module 34 call 0 */
        CHECK_ERROR(_readMethod_dappstaking_maintenance_mode_V2(c, &method->nested.dappstaking_maintenance_mode_V2))
        break;
    case 8705: /* module 34 call 1 */
        CHECK_ERROR(_readMethod_dappstaking_register_V2(c, &method->nested.dappstaking_register_V2))
        break;
    case 8706: /* module 34 call 2 */
        CHECK_ERROR(_readMethod_dappstaking_set_dapp_reward_beneficiary_V2(c, &method->nested.dappstaking_set_dapp_reward_beneficiary_V2))
        break;
    case 8707: /* module 34 call 3 */
        CHECK_ERROR(_readMethod_dappstaking_set_dapp_owner_V2(c, &method->nested.dappstaking_set_dapp_owner_V2))
        break;
    case 8710: /* module 34 call 6 */
        CHECK_ERROR(_readMethod_dappstaking_unregister_V2(c, &method->nested.dappstaking_unregister_V2))
        break;
    case 8711: /* module 34 call 7 */
        CHECK_ERROR(_readMethod_dappstaking_lock_V2(c, &method->nested.dappstaking_lock_V2))
        break;
    case 8712: /* module 34 call 8 */
        CHECK_ERROR(_readMethod_dappstaking_unlock_V2(c, &method->nested.dappstaking_unlock_V2))
        break;
    case 8713: /* module 34 call 9 */
        CHECK_ERROR(_readMethod_dappstaking_claim_unlocked_V2(c, &method->nested.dappstaking_claim_unlocked_V2))
        break;
    case 8714: /* module 34 call 10 */
        CHECK_ERROR(_readMethod_dappstaking_relock_unlocking_V2(c, &method->nested.dappstaking_relock_unlocking_V2))
        break;
    case 8715: /* module 34 call 11 */
        CHECK_ERROR(_readMethod_dappstaking_stake_V2(c, &method->nested.dappstaking_stake_V2))
        break;
    case 8716: /* module 34 call 12 */
        CHECK_ERROR(_readMethod_dappstaking_unstake_V2(c, &method->nested.dappstaking_unstake_V2))
        break;
    case 8717: /* module 34 call 13 */
        CHECK_ERROR(_readMethod_dappstaking_claim_staker_rewards_V2(c, &method->nested.dappstaking_claim_staker_rewards_V2))
        break;
    case 8718: /* module 34 call 14 */
        CHECK_ERROR(_readMethod_dappstaking_claim_bonus_reward_V2(c, &method->nested.dappstaking_claim_bonus_reward_V2))
        break;
    case 8719: /* module 34 call 15 */
        CHECK_ERROR(_readMethod_dappstaking_claim_dapp_reward_V2(c, &method->nested.dappstaking_claim_dapp_reward_V2))
        break;
    case 8720: /* module 34 call 16 */
        CHECK_ERROR(_readMethod_dappstaking_unstake_from_unregistered_V2(c, &method->nested.dappstaking_unstake_from_unregistered_V2))
        break;
    case 8721: /* module 34 call 17 */
        CHECK_ERROR(_readMethod_dappstaking_cleanup_expired_entries_V2(c, &method->nested.dappstaking_cleanup_expired_entries_V2))
        break;
    case 15360: /* module 60 call 0 */
        CHECK_ERROR(_readMethod_evm_withdraw_V2(c, &method->nested.evm_withdraw_V2))
        break;
    case 65024: /* module 254 call 0 */
        CHECK_ERROR(_readMethod_dappstakingmigration_migrate_V2(c, &method->nested.dappstakingmigration_migrate_V2))
        break;

#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
    case 2560: /* module 10 call 0 */
        CHECK_ERROR(_readMethod_system_remark_V2(c, &method->nested.system_remark_V2))
        break;
    case 2821: /* module 11 call 5 */
        CHECK_ERROR(_readMethod_utility_with_weight_V2(c, &method->basic.utility_with_weight_V2))
        break;
    case 3584: /* module 14 call 0 */
        CHECK_ERROR(_readMethod_multisig_as_multi_threshold_1_V2(c, &method->nested.multisig_as_multi_threshold_1_V2))
        break;
    case 3585: /* module 14 call 1 */
        CHECK_ERROR(_readMethod_multisig_as_multi_V2(c, &method->nested.multisig_as_multi_V2))
        break;
    case 3586: /* module 14 call 2 */
        CHECK_ERROR(_readMethod_multisig_approve_as_multi_V2(c, &method->nested.multisig_approve_as_multi_V2))
        break;
    case 3587: /* module 14 call 3 */
        CHECK_ERROR(_readMethod_multisig_cancel_as_multi_V2(c, &method->nested.multisig_cancel_as_multi_V2))
        break;
    case 3840: /* module 15 call 0 */
        CHECK_ERROR(_readMethod_proxy_proxy_V2(c, &method->nested.proxy_proxy_V2))
        break;
    case 3841: /* module 15 call 1 */
        CHECK_ERROR(_readMethod_proxy_add_proxy_V2(c, &method->nested.proxy_add_proxy_V2))
        break;
    case 3842: /* module 15 call 2 */
        CHECK_ERROR(_readMethod_proxy_remove_proxy_V2(c, &method->nested.proxy_remove_proxy_V2))
        break;
    case 3843: /* module 15 call 3 */
        CHECK_ERROR(_readMethod_proxy_remove_proxies_V2(c, &method->basic.proxy_remove_proxies_V2))
        break;
    case 3844: /* module 15 call 4 */
        CHECK_ERROR(_readMethod_proxy_create_pure_V2(c, &method->nested.proxy_create_pure_V2))
        break;
    case 3845: /* module 15 call 5 */
        CHECK_ERROR(_readMethod_proxy_kill_pure_V2(c, &method->nested.proxy_kill_pure_V2))
        break;
    case 3846: /* module 15 call 6 */
        CHECK_ERROR(_readMethod_proxy_announce_V2(c, &method->basic.proxy_announce_V2))
        break;
    case 3847: /* module 15 call 7 */
        CHECK_ERROR(_readMethod_proxy_remove_announcement_V2(c, &method->basic.proxy_remove_announcement_V2))
        break;
    case 3848: /* module 15 call 8 */
        CHECK_ERROR(_readMethod_proxy_reject_announcement_V2(c, &method->basic.proxy_reject_announcement_V2))
        break;
    case 3849: /* module 15 call 9 */
        CHECK_ERROR(_readMethod_proxy_proxy_announced_V2(c, &method->basic.proxy_proxy_announced_V2))
        break;
    case 7937: /* module 31 call 1 */
        CHECK_ERROR(_readMethod_balances_set_balance_deprecated_V2(c, &method->nested.balances_set_balance_deprecated_V2))
        break;
    case 7941: /* module 31 call 5 */
        CHECK_ERROR(_readMethod_balances_force_unreserve_V2(c, &method->basic.balances_force_unreserve_V2))
        break;
    case 7942: /* module 31 call 6 */
        CHECK_ERROR(_readMethod_balances_upgrade_accounts_V2(c, &method->basic.balances_upgrade_accounts_V2))
        break;
    case 7944: /* module 31 call 8 */
        CHECK_ERROR(_readMethod_balances_force_set_balance_V2(c, &method->basic.balances_force_set_balance_V2))
        break;
    case 9216: /* module 36 call 0 */
        CHECK_ERROR(_readMethod_assets_create_V2(c, &method->basic.assets_create_V2))
        break;
    case 9217: /* module 36 call 1 */
        CHECK_ERROR(_readMethod_assets_force_create_V2(c, &method->basic.assets_force_create_V2))
        break;
    case 9218: /* module 36 call 2 */
        CHECK_ERROR(_readMethod_assets_start_destroy_V2(c, &method->basic.assets_start_destroy_V2))
        break;
    case 9219: /* module 36 call 3 */
        CHECK_ERROR(_readMethod_assets_destroy_accounts_V2(c, &method->basic.assets_destroy_accounts_V2))
        break;
    case 9220: /* module 36 call 4 */
        CHECK_ERROR(_readMethod_assets_destroy_approvals_V2(c, &method->basic.assets_destroy_approvals_V2))
        break;
    case 9221: /* module 36 call 5 */
        CHECK_ERROR(_readMethod_assets_finish_destroy_V2(c, &method->basic.assets_finish_destroy_V2))
        break;
    case 9222: /* module 36 call 6 */
        CHECK_ERROR(_readMethod_assets_mint_V2(c, &method->basic.assets_mint_V2))
        break;
    case 9223: /* module 36 call 7 */
        CHECK_ERROR(_readMethod_assets_burn_V2(c, &method->basic.assets_burn_V2))
        break;
    case 9224: /* module 36 call 8 */
        CHECK_ERROR(_readMethod_assets_transfer_V2(c, &method->basic.assets_transfer_V2))
        break;
    case 9225: /* module 36 call 9 */
        CHECK_ERROR(_readMethod_assets_transfer_keep_alive_V2(c, &method->basic.assets_transfer_keep_alive_V2))
        break;
    case 9226: /* module 36 call 10 */
        CHECK_ERROR(_readMethod_assets_force_transfer_V2(c, &method->basic.assets_force_transfer_V2))
        break;
    case 9227: /* module 36 call 11 */
        CHECK_ERROR(_readMethod_assets_freeze_V2(c, &method->basic.assets_freeze_V2))
        break;
    case 9228: /* module 36 call 12 */
        CHECK_ERROR(_readMethod_assets_thaw_V2(c, &method->basic.assets_thaw_V2))
        break;
    case 9229: /* module 36 call 13 */
        CHECK_ERROR(_readMethod_assets_freeze_asset_V2(c, &method->basic.assets_freeze_asset_V2))
        break;
    case 9230: /* module 36 call 14 */
        CHECK_ERROR(_readMethod_assets_thaw_asset_V2(c, &method->basic.assets_thaw_asset_V2))
        break;
    case 9231: /* module 36 call 15 */
        CHECK_ERROR(_readMethod_assets_transfer_ownership_V2(c, &method->basic.assets_transfer_ownership_V2))
        break;
    case 9232: /* module 36 call 16 */
        CHECK_ERROR(_readMethod_assets_set_team_V2(c, &method->basic.assets_set_team_V2))
        break;
    case 9233: /* module 36 call 17 */
        CHECK_ERROR(_readMethod_assets_set_metadata_V2(c, &method->basic.assets_set_metadata_V2))
        break;
    case 9234: /* module 36 call 18 */
        CHECK_ERROR(_readMethod_assets_clear_metadata_V2(c, &method->basic.assets_clear_metadata_V2))
        break;
    case 9235: /* module 36 call 19 */
        CHECK_ERROR(_readMethod_assets_force_set_metadata_V2(c, &method->basic.assets_force_set_metadata_V2))
        break;
    case 9236: /* module 36 call 20 */
        CHECK_ERROR(_readMethod_assets_force_clear_metadata_V2(c, &method->basic.assets_force_clear_metadata_V2))
        break;
    case 9237: /* module 36 call 21 */
        CHECK_ERROR(_readMethod_assets_force_asset_status_V2(c, &method->basic.assets_force_asset_status_V2))
        break;
    case 9238: /* module 36 call 22 */
        CHECK_ERROR(_readMethod_assets_approve_transfer_V2(c, &method->basic.assets_approve_transfer_V2))
        break;
    case 9239: /* module 36 call 23 */
        CHECK_ERROR(_readMethod_assets_cancel_approval_V2(c, &method->basic.assets_cancel_approval_V2))
        break;
    case 9240: /* module 36 call 24 */
        CHECK_ERROR(_readMethod_assets_force_cancel_approval_V2(c, &method->basic.assets_force_cancel_approval_V2))
        break;
    case 9241: /* module 36 call 25 */
        CHECK_ERROR(_readMethod_assets_transfer_approved_V2(c, &method->basic.assets_transfer_approved_V2))
        break;
    case 9242: /* module 36 call 26 */
        CHECK_ERROR(_readMethod_assets_touch_V2(c, &method->basic.assets_touch_V2))
        break;
    case 9243: /* module 36 call 27 */
        CHECK_ERROR(_readMethod_assets_refund_V2(c, &method->basic.assets_refund_V2))
        break;
    case 9244: /* module 36 call 28 */
        CHECK_ERROR(_readMethod_assets_set_min_balance_V2(c, &method->basic.assets_set_min_balance_V2))
        break;
    case 9245: /* module 36 call 29 */
        CHECK_ERROR(_readMethod_assets_touch_other_V2(c, &method->basic.assets_touch_other_V2))
        break;
    case 9246: /* module 36 call 30 */
        CHECK_ERROR(_readMethod_assets_refund_other_V2(c, &method->basic.assets_refund_other_V2))
        break;
    case 9247: /* module 36 call 31 */
        CHECK_ERROR(_readMethod_assets_block_V2(c, &method->basic.assets_block_V2))
        break;
#endif
    default:
        return parser_unexpected_callIndex;
    }

    return parser_ok;
}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

const char* _getMethod_ModuleName_V2(uint8_t moduleIdx)
{
    switch (moduleIdx) {
    case 11:
        return STR_MO_UTILITY;
    case 31:
        return STR_MO_BALANCES;
    case 32:
        return STR_MO_VESTING;
    case 34:
        return STR_MO_DAPPSTAKING;
    case 60:
        return STR_MO_EVM;
    case 254:
        return STR_MO_DAPPSTAKINGMIGRATION;
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
    case 10:
        return STR_MO_SYSTEM;
    case 14:
        return STR_MO_MULTISIG;
    case 15:
        return STR_MO_PROXY;
    case 36:
        return STR_MO_ASSETS;
#endif
    default:
        return NULL;
    }

    return NULL;
}

const char* _getMethod_Name_V2(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 2816: /* module 11 call 0 */
        return STR_ME_BATCH;
    case 2818: /* module 11 call 2 */
        return STR_ME_BATCH_ALL;
    case 2820: /* module 11 call 4 */
        return STR_ME_FORCE_BATCH;
    case 7936: /* module 31 call 0 */
        return STR_ME_TRANSFER_ALLOW_DEATH;
    case 7938: /* module 31 call 2 */
        return STR_ME_FORCE_TRANSFER;
    case 7939: /* module 31 call 3 */
        return STR_ME_TRANSFER_KEEP_ALIVE;
    case 7940: /* module 31 call 4 */
        return STR_ME_TRANSFER_ALL;
    case 7943: /* module 31 call 7 */
        return STR_ME_TRANSFER;
    case 8192: /* module 32 call 0 */
        return STR_ME_VEST;
    case 8193: /* module 32 call 1 */
        return STR_ME_VEST_OTHER;
    case 8194: /* module 32 call 2 */
        return STR_ME_VESTED_TRANSFER;
    case 8195: /* module 32 call 3 */
        return STR_ME_FORCE_VESTED_TRANSFER;
    case 8196: /* module 32 call 4 */
        return STR_ME_MERGE_SCHEDULES;
    case 8708: /* module 34 call 4 */
        return STR_ME_UNBOND_AND_UNSTAKE;
    case 8709: /* module 34 call 5 */
        return STR_ME_WITHDRAW_UNBONDED;
    case 8704: /* module 34 call 0 */
        return STR_ME_MAINTENANCE_MODE;
    case 8705: /* module 34 call 1 */
        return STR_ME_REGISTER;
    case 8706: /* module 34 call 2 */
        return STR_ME_SET_DAPP_REWARD_BENEFICIARY;
    case 8707: /* module 34 call 3 */
        return STR_ME_SET_DAPP_OWNER;
    case 8710: /* module 34 call 6 */
        return STR_ME_UNREGISTER;
    case 8711: /* module 34 call 7 */
        return STR_ME_LOCK;
    case 8712: /* module 34 call 8 */
        return STR_ME_UNLOCK;
    case 8713: /* module 34 call 9 */
        return STR_ME_CLAIM_UNLOCKED;
    case 8714: /* module 34 call 10 */
        return STR_ME_RELOCK_UNLOCKING;
    case 8715: /* module 34 call 11 */
        return STR_ME_STAKE;
    case 8716: /* module 34 call 12 */
        return STR_ME_UNSTAKE;
    case 8717: /* module 34 call 13 */
        return STR_ME_CLAIM_STAKER_REWARDS;
    case 8718: /* module 34 call 14 */
        return STR_ME_CLAIM_BONUS_REWARD;
    case 8719: /* module 34 call 15 */
        return STR_ME_CLAIM_DAPP_REWARD;
    case 8720: /* module 34 call 16 */
        return STR_ME_UNSTAKE_FROM_UNREGISTERED;
    case 8721: /* module 34 call 17 */
        return STR_ME_CLEANUP_EXPIRED_ENTRIES;
    case 15360: /* module 60 call 0 */
        return STR_ME_WITHDRAW;
    case 65024: /* module 254 call 0 */
        return STR_ME_MIGRATE;
    default:
        return _getMethod_Name_V2_ParserFull(callPrivIdx);
    }

    return NULL;
}

const char* _getMethod_Name_V2_ParserFull(uint16_t callPrivIdx)
{
    switch (callPrivIdx) {
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
    case 2560: /* module 10 call 0 */
        return STR_ME_REMARK;
    case 2821: /* module 11 call 5 */
        return STR_ME_WITH_WEIGHT;
    case 3584: /* module 14 call 0 */
        return STR_ME_AS_MULTI_THRESHOLD_1;
    case 3585: /* module 14 call 1 */
        return STR_ME_AS_MULTI;
    case 3586: /* module 14 call 2 */
        return STR_ME_APPROVE_AS_MULTI;
    case 3587: /* module 14 call 3 */
        return STR_ME_CANCEL_AS_MULTI;
    case 3840: /* module 15 call 0 */
        return STR_ME_PROXY;
    case 3841: /* module 15 call 1 */
        return STR_ME_ADD_PROXY;
    case 3842: /* module 15 call 2 */
        return STR_ME_REMOVE_PROXY;
    case 3843: /* module 15 call 3 */
        return STR_ME_REMOVE_PROXIES;
    case 3844: /* module 15 call 4 */
        return STR_ME_CREATE_PURE;
    case 3845: /* module 15 call 5 */
        return STR_ME_KILL_PURE;
    case 3846: /* module 15 call 6 */
        return STR_ME_ANNOUNCE;
    case 3847: /* module 15 call 7 */
        return STR_ME_REMOVE_ANNOUNCEMENT;
    case 3848: /* module 15 call 8 */
        return STR_ME_REJECT_ANNOUNCEMENT;
    case 3849: /* module 15 call 9 */
        return STR_ME_PROXY_ANNOUNCED;
    case 7937: /* module 31 call 1 */
        return STR_ME_SET_BALANCE_DEPRECATED;
    case 7941: /* module 31 call 5 */
        return STR_ME_FORCE_UNRESERVE;
    case 7942: /* module 31 call 6 */
        return STR_ME_UPGRADE_ACCOUNTS;
    case 7944: /* module 31 call 8 */
        return STR_ME_FORCE_SET_BALANCE;
    case 9216: /* module 36 call 0 */
        return STR_ME_CREATE;
    case 9217: /* module 36 call 1 */
        return STR_ME_FORCE_CREATE;
    case 9218: /* module 36 call 2 */
        return STR_ME_START_DESTROY;
    case 9219: /* module 36 call 3 */
        return STR_ME_DESTROY_ACCOUNTS;
    case 9220: /* module 36 call 4 */
        return STR_ME_DESTROY_APPROVALS;
    case 9221: /* module 36 call 5 */
        return STR_ME_FINISH_DESTROY;
    case 9222: /* module 36 call 6 */
        return STR_ME_MINT;
    case 9223: /* module 36 call 7 */
        return STR_ME_BURN;
    case 9224: /* module 36 call 8 */
        return STR_ME_TRANSFER;
    case 9225: /* module 36 call 9 */
        return STR_ME_TRANSFER_KEEP_ALIVE;
    case 9226: /* module 36 call 10 */
        return STR_ME_FORCE_TRANSFER;
    case 9227: /* module 36 call 11 */
        return STR_ME_FREEZE;
    case 9228: /* module 36 call 12 */
        return STR_ME_THAW;
    case 9229: /* module 36 call 13 */
        return STR_ME_FREEZE_ASSET;
    case 9230: /* module 36 call 14 */
        return STR_ME_THAW_ASSET;
    case 9231: /* module 36 call 15 */
        return STR_ME_TRANSFER_OWNERSHIP;
    case 9232: /* module 36 call 16 */
        return STR_ME_SET_TEAM;
    case 9233: /* module 36 call 17 */
        return STR_ME_SET_METADATA;
    case 9234: /* module 36 call 18 */
        return STR_ME_CLEAR_METADATA;
    case 9235: /* module 36 call 19 */
        return STR_ME_FORCE_SET_METADATA;
    case 9236: /* module 36 call 20 */
        return STR_ME_FORCE_CLEAR_METADATA;
    case 9237: /* module 36 call 21 */
        return STR_ME_FORCE_ASSET_STATUS;
    case 9238: /* module 36 call 22 */
        return STR_ME_APPROVE_TRANSFER;
    case 9239: /* module 36 call 23 */
        return STR_ME_CANCEL_APPROVAL;
    case 9240: /* module 36 call 24 */
        return STR_ME_FORCE_CANCEL_APPROVAL;
    case 9241: /* module 36 call 25 */
        return STR_ME_TRANSFER_APPROVED;
    case 9242: /* module 36 call 26 */
        return STR_ME_TOUCH;
    case 9243: /* module 36 call 27 */
        return STR_ME_REFUND;
    case 9244: /* module 36 call 28 */
        return STR_ME_SET_MIN_BALANCE;
    case 9245: /* module 36 call 29 */
        return STR_ME_TOUCH_OTHER;
    case 9246: /* module 36 call 30 */
        return STR_ME_REFUND_OTHER;
    case 9247: /* module 36 call 31 */
        return STR_ME_BLOCK;
#endif
    default:
        return NULL;
    }

    return NULL;
}

uint8_t _getMethod_NumItems_V2(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 2816: /* module 11 call 0 */
        return 1;
    case 2818: /* module 11 call 2 */
        return 1;
    case 2820: /* module 11 call 4 */
        return 1;
    case 7936: /* module 31 call 0 */
        return 2;
    case 7938: /* module 31 call 2 */
        return 3;
    case 7939: /* module 31 call 3 */
        return 2;
    case 7940: /* module 31 call 4 */
        return 2;
    case 7943: /* module 31 call 7 */
        return 2;
    case 8192: /* module 32 call 0 */
        return 0;
    case 8193: /* module 32 call 1 */
        return 1;
    case 8194: /* module 32 call 2 */
        return 2;
    case 8195: /* module 32 call 3 */
        return 3;
    case 8196: /* module 32 call 4 */
        return 2;
    case 8708: /* module 34 call 4 */
        return 2;
    case 8709: /* module 34 call 5 */
        return 0;
    case 8704: /* module 34 call 0 */
        return 1;
    case 8705: /* module 34 call 1 */
        return 2;
    case 8706: /* module 34 call 2 */
        return 2;
    case 8707: /* module 34 call 3 */
        return 2;
    case 8710: /* module 34 call 6 */
        return 1;
    case 8711: /* module 34 call 7 */
        return 1;
    case 8712: /* module 34 call 8 */
        return 1;
    case 8713: /* module 34 call 9 */
        return 0;
    case 8714: /* module 34 call 10 */
        return 0;
    case 8715: /* module 34 call 11 */
        return 2;
    case 8716: /* module 34 call 12 */
        return 2;
    case 8717: /* module 34 call 13 */
        return 0;
    case 8718: /* module 34 call 14 */
        return 1;
    case 8719: /* module 34 call 15 */
        return 2;
    case 8720: /* module 34 call 16 */
        return 1;
    case 8721: /* module 34 call 17 */
        return 0;
    case 15360: /* module 60 call 0 */
        return 2;
    case 65024: /* module 254 call 0 */
        return 1;
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
    case 2560: /* module 10 call 0 */
        return 1;
    case 2821: /* module 11 call 5 */
        return 2;
    case 3584: /* module 14 call 0 */
        return 2;
    case 3585: /* module 14 call 1 */
        return 5;
    case 3586: /* module 14 call 2 */
        return 5;
    case 3587: /* module 14 call 3 */
        return 4;
    case 3840: /* module 15 call 0 */
        return 3;
    case 3841: /* module 15 call 1 */
        return 3;
    case 3842: /* module 15 call 2 */
        return 3;
    case 3843: /* module 15 call 3 */
        return 0;
    case 3844: /* module 15 call 4 */
        return 3;
    case 3845: /* module 15 call 5 */
        return 5;
    case 3846: /* module 15 call 6 */
        return 2;
    case 3847: /* module 15 call 7 */
        return 2;
    case 3848: /* module 15 call 8 */
        return 2;
    case 3849: /* module 15 call 9 */
        return 4;
    case 7937: /* module 31 call 1 */
        return 3;
    case 7941: /* module 31 call 5 */
        return 2;
    case 7942: /* module 31 call 6 */
        return 1;
    case 7944: /* module 31 call 8 */
        return 2;
    case 9216: /* module 36 call 0 */
        return 3;
    case 9217: /* module 36 call 1 */
        return 4;
    case 9218: /* module 36 call 2 */
        return 1;
    case 9219: /* module 36 call 3 */
        return 1;
    case 9220: /* module 36 call 4 */
        return 1;
    case 9221: /* module 36 call 5 */
        return 1;
    case 9222: /* module 36 call 6 */
        return 3;
    case 9223: /* module 36 call 7 */
        return 3;
    case 9224: /* module 36 call 8 */
        return 3;
    case 9225: /* module 36 call 9 */
        return 3;
    case 9226: /* module 36 call 10 */
        return 4;
    case 9227: /* module 36 call 11 */
        return 2;
    case 9228: /* module 36 call 12 */
        return 2;
    case 9229: /* module 36 call 13 */
        return 1;
    case 9230: /* module 36 call 14 */
        return 1;
    case 9231: /* module 36 call 15 */
        return 2;
    case 9232: /* module 36 call 16 */
        return 4;
    case 9233: /* module 36 call 17 */
        return 4;
    case 9234: /* module 36 call 18 */
        return 1;
    case 9235: /* module 36 call 19 */
        return 5;
    case 9236: /* module 36 call 20 */
        return 1;
    case 9237: /* module 36 call 21 */
        return 8;
    case 9238: /* module 36 call 22 */
        return 3;
    case 9239: /* module 36 call 23 */
        return 2;
    case 9240: /* module 36 call 24 */
        return 3;
    case 9241: /* module 36 call 25 */
        return 4;
    case 9242: /* module 36 call 26 */
        return 1;
    case 9243: /* module 36 call 27 */
        return 2;
    case 9244: /* module 36 call 28 */
        return 2;
    case 9245: /* module 36 call 29 */
        return 2;
    case 9246: /* module 36 call 30 */
        return 2;
    case 9247: /* module 36 call 31 */
        return 2;
#endif
    default:
        return 0;
    }

    return 0;
}

const char* _getMethod_ItemName_V2(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 2816: /* module 11 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_calls;
        default:
            return NULL;
        }
    case 2818: /* module 11 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_calls;
        default:
            return NULL;
        }
    case 2820: /* module 11 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_calls;
        default:
            return NULL;
        }
    case 7936: /* module 31 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 7938: /* module 31 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_source;
        case 1:
            return STR_IT_dest;
        case 2:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 7939: /* module 31 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 7940: /* module 31 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_keep_alive;
        default:
            return NULL;
        }
    case 7943: /* module 31 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 8192: /* module 32 call 0 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 8193: /* module 32 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        default:
            return NULL;
        }
    case 8194: /* module 32 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        case 1:
            return STR_IT_schedule;
        default:
            return NULL;
        }
    case 8195: /* module 32 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_source;
        case 1:
            return STR_IT_target;
        case 2:
            return STR_IT_schedule;
        default:
            return NULL;
        }
    case 8196: /* module 32 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_schedule1_index;
        case 1:
            return STR_IT_schedule2_index;
        default:
            return NULL;
        }
    case 8708: /* module 34 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_contract_id;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 8709: /* module 34 call 5 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 8704: /* module 34 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_enabled;
        default:
            return NULL;
        }
    case 8705: /* module 34 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_owner;
        case 1:
            return STR_IT_smart_contract;
        default:
            return NULL;
        }
    case 8706: /* module 34 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_smart_contract;
        case 1:
            return STR_IT_beneficiary;
        default:
            return NULL;
        }
    case 8707: /* module 34 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_smart_contract;
        case 1:
            return STR_IT_new_owner;
        default:
            return NULL;
        }
    case 8710: /* module 34 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_smart_contract;
        default:
            return NULL;
        }
    case 8711: /* module 34 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 8712: /* module 34 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 8713: /* module 34 call 9 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 8714: /* module 34 call 10 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 8715: /* module 34 call 11 */
        switch (itemIdx) {
        case 0:
            return STR_IT_smart_contract;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 8716: /* module 34 call 12 */
        switch (itemIdx) {
        case 0:
            return STR_IT_smart_contract;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 8717: /* module 34 call 13 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 8718: /* module 34 call 14 */
        switch (itemIdx) {
        case 0:
            return STR_IT_smart_contract;
        default:
            return NULL;
        }
    case 8719: /* module 34 call 15 */
        switch (itemIdx) {
        case 0:
            return STR_IT_smart_contract;
        case 1:
            return STR_IT_era;
        default:
            return NULL;
        }
    case 8720: /* module 34 call 16 */
        switch (itemIdx) {
        case 0:
            return STR_IT_smart_contract;
        default:
            return NULL;
        }
    case 8721: /* module 34 call 17 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 15360: /* module 60 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_address;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 65024: /* module 254 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_weight_limit;
        default:
            return NULL;
        }
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
    case 2560: /* module 10 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_remark;
        default:
            return NULL;
        }
    case 2821: /* module 11 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_call;
        case 1:
            return STR_IT_weight;
        default:
            return NULL;
        }
    case 3584: /* module 14 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_other_signatories;
        case 1:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 3585: /* module 14 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_threshold;
        case 1:
            return STR_IT_other_signatories;
        case 2:
            return STR_IT_maybe_timepoint;
        case 3:
            return STR_IT_call;
        case 4:
            return STR_IT_max_weight;
        default:
            return NULL;
        }
    case 3586: /* module 14 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_threshold;
        case 1:
            return STR_IT_other_signatories;
        case 2:
            return STR_IT_maybe_timepoint;
        case 3:
            return STR_IT_call_hash;
        case 4:
            return STR_IT_max_weight;
        default:
            return NULL;
        }
    case 3587: /* module 14 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_threshold;
        case 1:
            return STR_IT_other_signatories;
        case 2:
            return STR_IT_timepoint;
        case 3:
            return STR_IT_call_hash;
        default:
            return NULL;
        }
    case 3840: /* module 15 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_real;
        case 1:
            return STR_IT_force_proxy_type;
        case 2:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 3841: /* module 15 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_delegate;
        case 1:
            return STR_IT_proxy_type;
        case 2:
            return STR_IT_delay;
        default:
            return NULL;
        }
    case 3842: /* module 15 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_delegate;
        case 1:
            return STR_IT_proxy_type;
        case 2:
            return STR_IT_delay;
        default:
            return NULL;
        }
    case 3843: /* module 15 call 3 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 3844: /* module 15 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proxy_type;
        case 1:
            return STR_IT_delay;
        case 2:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 3845: /* module 15 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_spawner;
        case 1:
            return STR_IT_proxy_type;
        case 2:
            return STR_IT_index;
        case 3:
            return STR_IT_height;
        case 4:
            return STR_IT_ext_index;
        default:
            return NULL;
        }
    case 3846: /* module 15 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_real;
        case 1:
            return STR_IT_call_hash;
        default:
            return NULL;
        }
    case 3847: /* module 15 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_real;
        case 1:
            return STR_IT_call_hash;
        default:
            return NULL;
        }
    case 3848: /* module 15 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_delegate;
        case 1:
            return STR_IT_call_hash;
        default:
            return NULL;
        }
    case 3849: /* module 15 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_delegate;
        case 1:
            return STR_IT_real;
        case 2:
            return STR_IT_force_proxy_type;
        case 3:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 7937: /* module 31 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_new_free;
        case 2:
            return STR_IT_old_reserved;
        default:
            return NULL;
        }
    case 7941: /* module 31 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 7942: /* module 31 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 7944: /* module 31 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_new_free;
        default:
            return NULL;
        }
    case 9216: /* module 36 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_admin;
        case 2:
            return STR_IT_min_balance;
        default:
            return NULL;
        }
    case 9217: /* module 36 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_owner;
        case 2:
            return STR_IT_is_sufficient;
        case 3:
            return STR_IT_min_balance;
        default:
            return NULL;
        }
    case 9218: /* module 36 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 9219: /* module 36 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 9220: /* module 36 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 9221: /* module 36 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 9222: /* module 36 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_beneficiary;
        case 2:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 9223: /* module 36 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_who;
        case 2:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 9224: /* module 36 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_target;
        case 2:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 9225: /* module 36 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_target;
        case 2:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 9226: /* module 36 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_source;
        case 2:
            return STR_IT_dest;
        case 3:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 9227: /* module 36 call 11 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 9228: /* module 36 call 12 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 9229: /* module 36 call 13 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 9230: /* module 36 call 14 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 9231: /* module 36 call 15 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_owner;
        default:
            return NULL;
        }
    case 9232: /* module 36 call 16 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_issuer;
        case 2:
            return STR_IT_admin;
        case 3:
            return STR_IT_freezer;
        default:
            return NULL;
        }
    case 9233: /* module 36 call 17 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_name;
        case 2:
            return STR_IT_symbol;
        case 3:
            return STR_IT_decimals;
        default:
            return NULL;
        }
    case 9234: /* module 36 call 18 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 9235: /* module 36 call 19 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_name;
        case 2:
            return STR_IT_symbol;
        case 3:
            return STR_IT_decimals;
        case 4:
            return STR_IT_is_frozen;
        default:
            return NULL;
        }
    case 9236: /* module 36 call 20 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 9237: /* module 36 call 21 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_owner;
        case 2:
            return STR_IT_issuer;
        case 3:
            return STR_IT_admin;
        case 4:
            return STR_IT_freezer;
        case 5:
            return STR_IT_min_balance;
        case 6:
            return STR_IT_is_sufficient;
        case 7:
            return STR_IT_is_frozen;
        default:
            return NULL;
        }
    case 9238: /* module 36 call 22 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_delegate;
        case 2:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 9239: /* module 36 call 23 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_delegate;
        default:
            return NULL;
        }
    case 9240: /* module 36 call 24 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_owner;
        case 2:
            return STR_IT_delegate;
        default:
            return NULL;
        }
    case 9241: /* module 36 call 25 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_owner;
        case 2:
            return STR_IT_destination;
        case 3:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 9242: /* module 36 call 26 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 9243: /* module 36 call 27 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_allow_burn;
        default:
            return NULL;
        }
    case 9244: /* module 36 call 28 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_min_balance;
        default:
            return NULL;
        }
    case 9245: /* module 36 call 29 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 9246: /* module 36 call 30 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 9247: /* module 36 call 31 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_who;
        default:
            return NULL;
        }
#endif
    default:
        return NULL;
    }

    return NULL;
}

parser_error_t _getMethod_ItemValue_V2(
    pd_Method_V2_t* m,
    uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx,
    char* outValue, uint16_t outValueLen,
    uint8_t pageIdx, uint8_t* pageCount)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 2816: /* module 11 call 0 */
        switch (itemIdx) {
        case 0: /* utility_batch_V2 - calls */;
            return _toStringVecCall(
                &m->basic.utility_batch_V2.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2818: /* module 11 call 2 */
        switch (itemIdx) {
        case 0: /* utility_batch_all_V2 - calls */;
            return _toStringVecCall(
                &m->basic.utility_batch_all_V2.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2820: /* module 11 call 4 */
        switch (itemIdx) {
        case 0: /* utility_force_batch_V2 - calls */;
            return _toStringVecCall(
                &m->basic.utility_force_batch_V2.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7936: /* module 31 call 0 */
        switch (itemIdx) {
        case 0: /* balances_transfer_allow_death_V2 - dest */;
            return _toStringAccountIdLookupOfT(
                &m->nested.balances_transfer_allow_death_V2.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_allow_death_V2 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_transfer_allow_death_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7938: /* module 31 call 2 */
        switch (itemIdx) {
        case 0: /* balances_force_transfer_V2 - source */;
            return _toStringAccountIdLookupOfT(
                &m->nested.balances_force_transfer_V2.source,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_force_transfer_V2 - dest */;
            return _toStringAccountIdLookupOfT(
                &m->nested.balances_force_transfer_V2.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* balances_force_transfer_V2 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_force_transfer_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7939: /* module 31 call 3 */
        switch (itemIdx) {
        case 0: /* balances_transfer_keep_alive_V2 - dest */;
            return _toStringAccountIdLookupOfT(
                &m->nested.balances_transfer_keep_alive_V2.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_keep_alive_V2 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_transfer_keep_alive_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7940: /* module 31 call 4 */
        switch (itemIdx) {
        case 0: /* balances_transfer_all_V2 - dest */;
            return _toStringAccountIdLookupOfT(
                &m->nested.balances_transfer_all_V2.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_all_V2 - keep_alive */;
            return _toStringbool(
                &m->nested.balances_transfer_all_V2.keep_alive,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7943: /* module 31 call 7 */
        switch (itemIdx) {
        case 0: /* balances_transfer_V2 - dest */;
            return _toStringAccountIdLookupOfT(
                &m->nested.balances_transfer_V2.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_V2 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_transfer_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8192: /* module 32 call 0 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 8193: /* module 32 call 1 */
        switch (itemIdx) {
        case 0: /* vesting_vest_other_V2 - target */;
            return _toStringAccountIdLookupOfT(
                &m->nested.vesting_vest_other_V2.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8194: /* module 32 call 2 */
        switch (itemIdx) {
        case 0: /* vesting_vested_transfer_V2 - target */;
            return _toStringAccountIdLookupOfT(
                &m->nested.vesting_vested_transfer_V2.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* vesting_vested_transfer_V2 - schedule */;
            return _toStringVestingInfo(
                &m->nested.vesting_vested_transfer_V2.schedule,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8195: /* module 32 call 3 */
        switch (itemIdx) {
        case 0: /* vesting_force_vested_transfer_V2 - source */;
            return _toStringAccountIdLookupOfT(
                &m->nested.vesting_force_vested_transfer_V2.source,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* vesting_force_vested_transfer_V2 - target */;
            return _toStringAccountIdLookupOfT(
                &m->nested.vesting_force_vested_transfer_V2.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* vesting_force_vested_transfer_V2 - schedule */;
            return _toStringVestingInfo(
                &m->nested.vesting_force_vested_transfer_V2.schedule,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8196: /* module 32 call 4 */
        switch (itemIdx) {
        case 0: /* vesting_merge_schedules_V2 - schedule1_index */;
            return _toStringu32(
                &m->nested.vesting_merge_schedules_V2.schedule1_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* vesting_merge_schedules_V2 - schedule2_index */;
            return _toStringu32(
                &m->nested.vesting_merge_schedules_V2.schedule2_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8708: /* module 34 call 4 */
        switch (itemIdx) {
        case 0: /* dappstaking_unbond_and_unstake_V2 - contract_id */;
            return _toStringSmartContract(
                &m->nested.dappstaking_unbond_and_unstake_V2.contract_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* dappstaking_unbond_and_unstake_V2 - amount */;
            return _toStringCompactu128(
                &m->nested.dappstaking_unbond_and_unstake_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8709: /* module 34 call 5 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 8704: /* module 34 call 0 */
        switch (itemIdx) {
        case 0: /* dappstaking_maintenance_mode_V2 - enabled */;
            return _toStringbool(
                &m->nested.dappstaking_maintenance_mode_V2.enabled,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8705: /* module 34 call 1 */
        switch (itemIdx) {
        case 0: /* dappstaking_register_V2 - owner */;
            return _toStringAccountId(
                &m->nested.dappstaking_register_V2.owner,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* dappstaking_register_V2 - smart_contract */;
            return _toStringSmartContract(
                &m->nested.dappstaking_register_V2.smart_contract,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8706: /* module 34 call 2 */
        switch (itemIdx) {
        case 0: /* dappstaking_set_dapp_reward_beneficiary_V2 - smart_contract */;
            return _toStringSmartContract(
                &m->nested.dappstaking_set_dapp_reward_beneficiary_V2.smart_contract,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* dappstaking_set_dapp_reward_beneficiary_V2 - beneficiary */;
            return _toStringOptionAccountId(
                &m->nested.dappstaking_set_dapp_reward_beneficiary_V2.beneficiary,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8707: /* module 34 call 3 */
        switch (itemIdx) {
        case 0: /* dappstaking_set_dapp_owner_V2 - smart_contract */;
            return _toStringSmartContract(
                &m->nested.dappstaking_set_dapp_owner_V2.smart_contract,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* dappstaking_set_dapp_owner_V2 - new_owner */;
            return _toStringAccountId(
                &m->nested.dappstaking_set_dapp_owner_V2.new_owner,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8710: /* module 34 call 6 */
        switch (itemIdx) {
        case 0: /* dappstaking_unregister_V2 - smart_contract */;
            return _toStringSmartContract(
                &m->nested.dappstaking_unregister_V2.smart_contract,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8711: /* module 34 call 7 */
        switch (itemIdx) {
        case 0: /* dappstaking_lock_V2 - amount */;
            return _toStringCompactu128(
                &m->nested.dappstaking_lock_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8712: /* module 34 call 8 */
        switch (itemIdx) {
        case 0: /* dappstaking_unlock_V2 - amount */;
            return _toStringCompactu128(
                &m->nested.dappstaking_unlock_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8713: /* module 34 call 9 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 8714: /* module 34 call 10 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 8715: /* module 34 call 11 */
        switch (itemIdx) {
        case 0: /* dappstaking_stake_V2 - smart_contract */;
            return _toStringSmartContract(
                &m->nested.dappstaking_stake_V2.smart_contract,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* dappstaking_stake_V2 - amount */;
            return _toStringCompactu128(
                &m->nested.dappstaking_stake_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8716: /* module 34 call 12 */
        switch (itemIdx) {
        case 0: /* dappstaking_unstake_V2 - smart_contract */;
            return _toStringSmartContract(
                &m->nested.dappstaking_unstake_V2.smart_contract,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* dappstaking_unstake_V2 - amount */;
            return _toStringCompactu128(
                &m->nested.dappstaking_unstake_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8717: /* module 34 call 13 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 8718: /* module 34 call 14 */
        switch (itemIdx) {
        case 0: /* dappstaking_claim_bonus_reward_V2 - smart_contract */;
            return _toStringSmartContract(
                &m->nested.dappstaking_claim_bonus_reward_V2.smart_contract,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8719: /* module 34 call 15 */
        switch (itemIdx) {
        case 0: /* dappstaking_claim_dapp_reward_V2 - smart_contract */;
            return _toStringSmartContract(
                &m->nested.dappstaking_claim_dapp_reward_V2.smart_contract,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* dappstaking_claim_dapp_reward_V2 - era */;
            return _toStringCompactu32(
                &m->nested.dappstaking_claim_dapp_reward_V2.era,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8720: /* module 34 call 16 */
        switch (itemIdx) {
        case 0: /* dappstaking_unstake_from_unregistered_V2 - smart_contract */;
            return _toStringSmartContract(
                &m->nested.dappstaking_unstake_from_unregistered_V2.smart_contract,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8721: /* module 34 call 17 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 15360: /* module 60 call 0 */
        switch (itemIdx) {
        case 0: /* evm_withdraw_V2 - address */;
            return _toStringH160(
                &m->nested.evm_withdraw_V2.address,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* evm_withdraw_V2 - amount */;
            return _toStringBalance(
                &m->nested.evm_withdraw_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 65024: /* module 254 call 0 */
        switch (itemIdx) {
        case 0: /* dappstakingmigration_migrate_V2 - weight_limit */;
            return _toStringOptionWeight(
                &m->nested.dappstakingmigration_migrate_V2.weight_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
    case 2560: /* module 10 call 0 */
        switch (itemIdx) {
        case 0: /* system_remark_V2 - remark */;
            return _toStringBytes(
                &m->nested.system_remark_V2.remark,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2821: /* module 11 call 5 */
        switch (itemIdx) {
        case 0: /* utility_with_weight_V2 - call */;
            return _toStringCall(
                &m->basic.utility_with_weight_V2.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* utility_with_weight_V2 - weight */;
            return _toStringWeight(
                &m->basic.utility_with_weight_V2.weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3584: /* module 14 call 0 */
        switch (itemIdx) {
        case 0: /* multisig_as_multi_threshold_1_V2 - other_signatories */;
            return _toStringVecAccountId(
                &m->nested.multisig_as_multi_threshold_1_V2.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_as_multi_threshold_1_V2 - call */;
            return _toStringCall(
                &m->nested.multisig_as_multi_threshold_1_V2.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3585: /* module 14 call 1 */
        switch (itemIdx) {
        case 0: /* multisig_as_multi_V2 - threshold */;
            return _toStringu16(
                &m->nested.multisig_as_multi_V2.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_as_multi_V2 - other_signatories */;
            return _toStringVecAccountId(
                &m->nested.multisig_as_multi_V2.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_as_multi_V2 - maybe_timepoint */;
            return _toStringOptionTimepoint(
                &m->nested.multisig_as_multi_V2.maybe_timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_as_multi_V2 - call */;
            return _toStringCall(
                &m->nested.multisig_as_multi_V2.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* multisig_as_multi_V2 - max_weight */;
            return _toStringWeight(
                &m->nested.multisig_as_multi_V2.max_weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3586: /* module 14 call 2 */
        switch (itemIdx) {
        case 0: /* multisig_approve_as_multi_V2 - threshold */;
            return _toStringu16(
                &m->nested.multisig_approve_as_multi_V2.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_approve_as_multi_V2 - other_signatories */;
            return _toStringVecAccountId(
                &m->nested.multisig_approve_as_multi_V2.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_approve_as_multi_V2 - maybe_timepoint */;
            return _toStringOptionTimepoint(
                &m->nested.multisig_approve_as_multi_V2.maybe_timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_approve_as_multi_V2 - call_hash */;
            return _toStringH256(
                &m->nested.multisig_approve_as_multi_V2.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* multisig_approve_as_multi_V2 - max_weight */;
            return _toStringWeight(
                &m->nested.multisig_approve_as_multi_V2.max_weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3587: /* module 14 call 3 */
        switch (itemIdx) {
        case 0: /* multisig_cancel_as_multi_V2 - threshold */;
            return _toStringu16(
                &m->nested.multisig_cancel_as_multi_V2.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_cancel_as_multi_V2 - other_signatories */;
            return _toStringVecAccountId(
                &m->nested.multisig_cancel_as_multi_V2.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_cancel_as_multi_V2 - timepoint */;
            return _toStringTimepoint(
                &m->nested.multisig_cancel_as_multi_V2.timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_cancel_as_multi_V2 - call_hash */;
            return _toStringH256(
                &m->nested.multisig_cancel_as_multi_V2.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3840: /* module 15 call 0 */
        switch (itemIdx) {
        case 0: /* proxy_proxy_V2 - real */;
            return _toStringAccountIdLookupOfT(
                &m->nested.proxy_proxy_V2.real,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_proxy_V2 - force_proxy_type */;
            return _toStringOptionProxyType(
                &m->nested.proxy_proxy_V2.force_proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_proxy_V2 - call */;
            return _toStringCall(
                &m->nested.proxy_proxy_V2.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3841: /* module 15 call 1 */
        switch (itemIdx) {
        case 0: /* proxy_add_proxy_V2 - delegate */;
            return _toStringAccountIdLookupOfT(
                &m->nested.proxy_add_proxy_V2.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_add_proxy_V2 - proxy_type */;
            return _toStringProxyType(
                &m->nested.proxy_add_proxy_V2.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_add_proxy_V2 - delay */;
            return _toStringBlockNumber(
                &m->nested.proxy_add_proxy_V2.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3842: /* module 15 call 2 */
        switch (itemIdx) {
        case 0: /* proxy_remove_proxy_V2 - delegate */;
            return _toStringAccountIdLookupOfT(
                &m->nested.proxy_remove_proxy_V2.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_remove_proxy_V2 - proxy_type */;
            return _toStringProxyType(
                &m->nested.proxy_remove_proxy_V2.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_remove_proxy_V2 - delay */;
            return _toStringBlockNumber(
                &m->nested.proxy_remove_proxy_V2.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3843: /* module 15 call 3 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 3844: /* module 15 call 4 */
        switch (itemIdx) {
        case 0: /* proxy_create_pure_V2 - proxy_type */;
            return _toStringProxyType(
                &m->nested.proxy_create_pure_V2.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_create_pure_V2 - delay */;
            return _toStringBlockNumber(
                &m->nested.proxy_create_pure_V2.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_create_pure_V2 - index */;
            return _toStringu16(
                &m->nested.proxy_create_pure_V2.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3845: /* module 15 call 5 */
        switch (itemIdx) {
        case 0: /* proxy_kill_pure_V2 - spawner */;
            return _toStringAccountIdLookupOfT(
                &m->nested.proxy_kill_pure_V2.spawner,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_kill_pure_V2 - proxy_type */;
            return _toStringProxyType(
                &m->nested.proxy_kill_pure_V2.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_kill_pure_V2 - index */;
            return _toStringu16(
                &m->nested.proxy_kill_pure_V2.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* proxy_kill_pure_V2 - height */;
            return _toStringCompactu32(
                &m->nested.proxy_kill_pure_V2.height,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* proxy_kill_pure_V2 - ext_index */;
            return _toStringCompactu32(
                &m->nested.proxy_kill_pure_V2.ext_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3846: /* module 15 call 6 */
        switch (itemIdx) {
        case 0: /* proxy_announce_V2 - real */;
            return _toStringAccountIdLookupOfT(
                &m->basic.proxy_announce_V2.real,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_announce_V2 - call_hash */;
            return _toStringCallHashOf(
                &m->basic.proxy_announce_V2.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3847: /* module 15 call 7 */
        switch (itemIdx) {
        case 0: /* proxy_remove_announcement_V2 - real */;
            return _toStringAccountIdLookupOfT(
                &m->basic.proxy_remove_announcement_V2.real,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_remove_announcement_V2 - call_hash */;
            return _toStringCallHashOf(
                &m->basic.proxy_remove_announcement_V2.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3848: /* module 15 call 8 */
        switch (itemIdx) {
        case 0: /* proxy_reject_announcement_V2 - delegate */;
            return _toStringAccountIdLookupOfT(
                &m->basic.proxy_reject_announcement_V2.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_reject_announcement_V2 - call_hash */;
            return _toStringCallHashOf(
                &m->basic.proxy_reject_announcement_V2.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3849: /* module 15 call 9 */
        switch (itemIdx) {
        case 0: /* proxy_proxy_announced_V2 - delegate */;
            return _toStringAccountIdLookupOfT(
                &m->basic.proxy_proxy_announced_V2.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_proxy_announced_V2 - real */;
            return _toStringAccountIdLookupOfT(
                &m->basic.proxy_proxy_announced_V2.real,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_proxy_announced_V2 - force_proxy_type */;
            return _toStringOptionProxyType(
                &m->basic.proxy_proxy_announced_V2.force_proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* proxy_proxy_announced_V2 - call */;
            return _toStringCall(
                &m->basic.proxy_proxy_announced_V2.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7937: /* module 31 call 1 */
        switch (itemIdx) {
        case 0: /* balances_set_balance_deprecated_V2 - who */;
            return _toStringAccountIdLookupOfT(
                &m->nested.balances_set_balance_deprecated_V2.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_set_balance_deprecated_V2 - new_free */;
            return _toStringCompactBalance(
                &m->nested.balances_set_balance_deprecated_V2.new_free,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* balances_set_balance_deprecated_V2 - old_reserved */;
            return _toStringCompactBalance(
                &m->nested.balances_set_balance_deprecated_V2.old_reserved,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7941: /* module 31 call 5 */
        switch (itemIdx) {
        case 0: /* balances_force_unreserve_V2 - who */;
            return _toStringAccountIdLookupOfT(
                &m->basic.balances_force_unreserve_V2.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_force_unreserve_V2 - amount */;
            return _toStringBalance(
                &m->basic.balances_force_unreserve_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7942: /* module 31 call 6 */
        switch (itemIdx) {
        case 0: /* balances_upgrade_accounts_V2 - who */;
            return _toStringVecAccountId(
                &m->basic.balances_upgrade_accounts_V2.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7944: /* module 31 call 8 */
        switch (itemIdx) {
        case 0: /* balances_force_set_balance_V2 - who */;
            return _toStringAccountIdLookupOfT(
                &m->basic.balances_force_set_balance_V2.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_force_set_balance_V2 - new_free */;
            return _toStringCompactBalance(
                &m->basic.balances_force_set_balance_V2.new_free,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9216: /* module 36 call 0 */
        switch (itemIdx) {
        case 0: /* assets_create_V2 - id */;
            return _toStringCompactBalance(
                &m->basic.assets_create_V2.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_create_V2 - admin */;
            return _toStringAccountIdLookupOfT(
                &m->basic.assets_create_V2.admin,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_create_V2 - min_balance */;
            return _toStringBalance(
                &m->basic.assets_create_V2.min_balance,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9217: /* module 36 call 1 */
        switch (itemIdx) {
        case 0: /* assets_force_create_V2 - id */;
            return _toStringCompactBalance(
                &m->basic.assets_force_create_V2.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_force_create_V2 - owner */;
            return _toStringAccountIdLookupOfT(
                &m->basic.assets_force_create_V2.owner,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_force_create_V2 - is_sufficient */;
            return _toStringbool(
                &m->basic.assets_force_create_V2.is_sufficient,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* assets_force_create_V2 - min_balance */;
            return _toStringCompactBalance(
                &m->basic.assets_force_create_V2.min_balance,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9218: /* module 36 call 2 */
        switch (itemIdx) {
        case 0: /* assets_start_destroy_V2 - id */;
            return _toStringCompactBalance(
                &m->basic.assets_start_destroy_V2.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9219: /* module 36 call 3 */
        switch (itemIdx) {
        case 0: /* assets_destroy_accounts_V2 - id */;
            return _toStringCompactBalance(
                &m->basic.assets_destroy_accounts_V2.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9220: /* module 36 call 4 */
        switch (itemIdx) {
        case 0: /* assets_destroy_approvals_V2 - id */;
            return _toStringCompactBalance(
                &m->basic.assets_destroy_approvals_V2.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9221: /* module 36 call 5 */
        switch (itemIdx) {
        case 0: /* assets_finish_destroy_V2 - id */;
            return _toStringCompactBalance(
                &m->basic.assets_finish_destroy_V2.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9222: /* module 36 call 6 */
        switch (itemIdx) {
        case 0: /* assets_mint_V2 - id */;
            return _toStringCompactBalance(
                &m->basic.assets_mint_V2.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_mint_V2 - beneficiary */;
            return _toStringAccountIdLookupOfT(
                &m->basic.assets_mint_V2.beneficiary,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_mint_V2 - amount */;
            return _toStringCompactBalance(
                &m->basic.assets_mint_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9223: /* module 36 call 7 */
        switch (itemIdx) {
        case 0: /* assets_burn_V2 - id */;
            return _toStringCompactBalance(
                &m->basic.assets_burn_V2.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_burn_V2 - who */;
            return _toStringAccountIdLookupOfT(
                &m->basic.assets_burn_V2.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_burn_V2 - amount */;
            return _toStringCompactBalance(
                &m->basic.assets_burn_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9224: /* module 36 call 8 */
        switch (itemIdx) {
        case 0: /* assets_transfer_V2 - id */;
            return _toStringCompactBalance(
                &m->basic.assets_transfer_V2.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_transfer_V2 - target */;
            return _toStringAccountIdLookupOfT(
                &m->basic.assets_transfer_V2.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_transfer_V2 - amount */;
            return _toStringCompactBalance(
                &m->basic.assets_transfer_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9225: /* module 36 call 9 */
        switch (itemIdx) {
        case 0: /* assets_transfer_keep_alive_V2 - id */;
            return _toStringCompactBalance(
                &m->basic.assets_transfer_keep_alive_V2.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_transfer_keep_alive_V2 - target */;
            return _toStringAccountIdLookupOfT(
                &m->basic.assets_transfer_keep_alive_V2.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_transfer_keep_alive_V2 - amount */;
            return _toStringCompactBalance(
                &m->basic.assets_transfer_keep_alive_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9226: /* module 36 call 10 */
        switch (itemIdx) {
        case 0: /* assets_force_transfer_V2 - id */;
            return _toStringCompactBalance(
                &m->basic.assets_force_transfer_V2.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_force_transfer_V2 - source */;
            return _toStringAccountIdLookupOfT(
                &m->basic.assets_force_transfer_V2.source,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_force_transfer_V2 - dest */;
            return _toStringAccountIdLookupOfT(
                &m->basic.assets_force_transfer_V2.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* assets_force_transfer_V2 - amount */;
            return _toStringCompactBalance(
                &m->basic.assets_force_transfer_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9227: /* module 36 call 11 */
        switch (itemIdx) {
        case 0: /* assets_freeze_V2 - id */;
            return _toStringCompactBalance(
                &m->basic.assets_freeze_V2.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_freeze_V2 - who */;
            return _toStringAccountIdLookupOfT(
                &m->basic.assets_freeze_V2.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9228: /* module 36 call 12 */
        switch (itemIdx) {
        case 0: /* assets_thaw_V2 - id */;
            return _toStringCompactBalance(
                &m->basic.assets_thaw_V2.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_thaw_V2 - who */;
            return _toStringAccountIdLookupOfT(
                &m->basic.assets_thaw_V2.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9229: /* module 36 call 13 */
        switch (itemIdx) {
        case 0: /* assets_freeze_asset_V2 - id */;
            return _toStringCompactBalance(
                &m->basic.assets_freeze_asset_V2.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9230: /* module 36 call 14 */
        switch (itemIdx) {
        case 0: /* assets_thaw_asset_V2 - id */;
            return _toStringCompactBalance(
                &m->basic.assets_thaw_asset_V2.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9231: /* module 36 call 15 */
        switch (itemIdx) {
        case 0: /* assets_transfer_ownership_V2 - id */;
            return _toStringCompactBalance(
                &m->basic.assets_transfer_ownership_V2.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_transfer_ownership_V2 - owner */;
            return _toStringAccountIdLookupOfT(
                &m->basic.assets_transfer_ownership_V2.owner,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9232: /* module 36 call 16 */
        switch (itemIdx) {
        case 0: /* assets_set_team_V2 - id */;
            return _toStringCompactBalance(
                &m->basic.assets_set_team_V2.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_set_team_V2 - issuer */;
            return _toStringAccountIdLookupOfT(
                &m->basic.assets_set_team_V2.issuer,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_set_team_V2 - admin */;
            return _toStringAccountIdLookupOfT(
                &m->basic.assets_set_team_V2.admin,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* assets_set_team_V2 - freezer */;
            return _toStringAccountIdLookupOfT(
                &m->basic.assets_set_team_V2.freezer,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9233: /* module 36 call 17 */
        switch (itemIdx) {
        case 0: /* assets_set_metadata_V2 - id */;
            return _toStringCompactBalance(
                &m->basic.assets_set_metadata_V2.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_set_metadata_V2 - name */;
            return _toStringVecu8(
                &m->basic.assets_set_metadata_V2.name,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_set_metadata_V2 - symbol */;
            return _toStringVecu8(
                &m->basic.assets_set_metadata_V2.symbol,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* assets_set_metadata_V2 - decimals */;
            return _toStringu8(
                &m->basic.assets_set_metadata_V2.decimals,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9234: /* module 36 call 18 */
        switch (itemIdx) {
        case 0: /* assets_clear_metadata_V2 - id */;
            return _toStringCompactBalance(
                &m->basic.assets_clear_metadata_V2.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9235: /* module 36 call 19 */
        switch (itemIdx) {
        case 0: /* assets_force_set_metadata_V2 - id */;
            return _toStringCompactBalance(
                &m->basic.assets_force_set_metadata_V2.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_force_set_metadata_V2 - name */;
            return _toStringVecu8(
                &m->basic.assets_force_set_metadata_V2.name,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_force_set_metadata_V2 - symbol */;
            return _toStringVecu8(
                &m->basic.assets_force_set_metadata_V2.symbol,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* assets_force_set_metadata_V2 - decimals */;
            return _toStringu8(
                &m->basic.assets_force_set_metadata_V2.decimals,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* assets_force_set_metadata_V2 - is_frozen */;
            return _toStringbool(
                &m->basic.assets_force_set_metadata_V2.is_frozen,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9236: /* module 36 call 20 */
        switch (itemIdx) {
        case 0: /* assets_force_clear_metadata_V2 - id */;
            return _toStringCompactBalance(
                &m->basic.assets_force_clear_metadata_V2.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9237: /* module 36 call 21 */
        switch (itemIdx) {
        case 0: /* assets_force_asset_status_V2 - id */;
            return _toStringCompactBalance(
                &m->basic.assets_force_asset_status_V2.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_force_asset_status_V2 - owner */;
            return _toStringAccountIdLookupOfT(
                &m->basic.assets_force_asset_status_V2.owner,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_force_asset_status_V2 - issuer */;
            return _toStringAccountIdLookupOfT(
                &m->basic.assets_force_asset_status_V2.issuer,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* assets_force_asset_status_V2 - admin */;
            return _toStringAccountIdLookupOfT(
                &m->basic.assets_force_asset_status_V2.admin,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* assets_force_asset_status_V2 - freezer */;
            return _toStringAccountIdLookupOfT(
                &m->basic.assets_force_asset_status_V2.freezer,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* assets_force_asset_status_V2 - min_balance */;
            return _toStringCompactBalance(
                &m->basic.assets_force_asset_status_V2.min_balance,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 6: /* assets_force_asset_status_V2 - is_sufficient */;
            return _toStringbool(
                &m->basic.assets_force_asset_status_V2.is_sufficient,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 7: /* assets_force_asset_status_V2 - is_frozen */;
            return _toStringbool(
                &m->basic.assets_force_asset_status_V2.is_frozen,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9238: /* module 36 call 22 */
        switch (itemIdx) {
        case 0: /* assets_approve_transfer_V2 - id */;
            return _toStringCompactBalance(
                &m->basic.assets_approve_transfer_V2.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_approve_transfer_V2 - delegate */;
            return _toStringAccountIdLookupOfT(
                &m->basic.assets_approve_transfer_V2.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_approve_transfer_V2 - amount */;
            return _toStringCompactBalance(
                &m->basic.assets_approve_transfer_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9239: /* module 36 call 23 */
        switch (itemIdx) {
        case 0: /* assets_cancel_approval_V2 - id */;
            return _toStringCompactBalance(
                &m->basic.assets_cancel_approval_V2.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_cancel_approval_V2 - delegate */;
            return _toStringAccountIdLookupOfT(
                &m->basic.assets_cancel_approval_V2.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9240: /* module 36 call 24 */
        switch (itemIdx) {
        case 0: /* assets_force_cancel_approval_V2 - id */;
            return _toStringCompactBalance(
                &m->basic.assets_force_cancel_approval_V2.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_force_cancel_approval_V2 - owner */;
            return _toStringAccountIdLookupOfT(
                &m->basic.assets_force_cancel_approval_V2.owner,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_force_cancel_approval_V2 - delegate */;
            return _toStringAccountIdLookupOfT(
                &m->basic.assets_force_cancel_approval_V2.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9241: /* module 36 call 25 */
        switch (itemIdx) {
        case 0: /* assets_transfer_approved_V2 - id */;
            return _toStringCompactBalance(
                &m->basic.assets_transfer_approved_V2.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_transfer_approved_V2 - owner */;
            return _toStringAccountIdLookupOfT(
                &m->basic.assets_transfer_approved_V2.owner,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* assets_transfer_approved_V2 - destination */;
            return _toStringAccountIdLookupOfT(
                &m->basic.assets_transfer_approved_V2.destination,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* assets_transfer_approved_V2 - amount */;
            return _toStringCompactBalance(
                &m->basic.assets_transfer_approved_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9242: /* module 36 call 26 */
        switch (itemIdx) {
        case 0: /* assets_touch_V2 - id */;
            return _toStringCompactBalance(
                &m->basic.assets_touch_V2.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9243: /* module 36 call 27 */
        switch (itemIdx) {
        case 0: /* assets_refund_V2 - id */;
            return _toStringCompactBalance(
                &m->basic.assets_refund_V2.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_refund_V2 - allow_burn */;
            return _toStringbool(
                &m->basic.assets_refund_V2.allow_burn,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9244: /* module 36 call 28 */
        switch (itemIdx) {
        case 0: /* assets_set_min_balance_V2 - id */;
            return _toStringCompactBalance(
                &m->basic.assets_set_min_balance_V2.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_set_min_balance_V2 - min_balance */;
            return _toStringBalance(
                &m->basic.assets_set_min_balance_V2.min_balance,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9245: /* module 36 call 29 */
        switch (itemIdx) {
        case 0: /* assets_touch_other_V2 - id */;
            return _toStringCompactBalance(
                &m->basic.assets_touch_other_V2.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_touch_other_V2 - who */;
            return _toStringAccountIdLookupOfT(
                &m->basic.assets_touch_other_V2.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9246: /* module 36 call 30 */
        switch (itemIdx) {
        case 0: /* assets_refund_other_V2 - id */;
            return _toStringCompactBalance(
                &m->basic.assets_refund_other_V2.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_refund_other_V2 - who */;
            return _toStringAccountIdLookupOfT(
                &m->basic.assets_refund_other_V2.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9247: /* module 36 call 31 */
        switch (itemIdx) {
        case 0: /* assets_block_V2 - id */;
            return _toStringCompactBalance(
                &m->basic.assets_block_V2.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* assets_block_V2 - who */;
            return _toStringAccountIdLookupOfT(
                &m->basic.assets_block_V2.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
#endif
    default:
        return parser_ok;
    }

    return parser_ok;
}

bool _getMethod_ItemIsExpert_V2(uint8_t moduleIdx, uint8_t callIdx, __Z_UNUSED uint8_t itemIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {

    default:
        return false;
    }
}

bool _getMethod_IsNestingSupported_V2(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 2816: // Utility:Batch
    case 2818: // Utility:Batch all
    case 2820: // Utility:Force batch
    case 2821: // Utility:With weight
    case 3843: // Proxy:Remove proxies
    case 3846: // Proxy:Announce
    case 3847: // Proxy:Remove announcement
    case 3848: // Proxy:Reject announcement
    case 3849: // Proxy:Proxy announced
    case 7941: // Balances:Force unreserve
    case 7942: // Balances:Upgrade accounts
    case 7944: // Balances:Force set balance
    case 9216: // Assets:Create
    case 9217: // Assets:Force create
    case 9218: // Assets:Start destroy
    case 9219: // Assets:Destroy accounts
    case 9220: // Assets:Destroy approvals
    case 9221: // Assets:Finish destroy
    case 9222: // Assets:Mint
    case 9223: // Assets:Burn
    case 9224: // Assets:Transfer
    case 9225: // Assets:Transfer keep alive
    case 9226: // Assets:Force transfer
    case 9227: // Assets:Freeze
    case 9228: // Assets:Thaw
    case 9229: // Assets:Freeze asset
    case 9230: // Assets:Thaw asset
    case 9231: // Assets:Transfer ownership
    case 9232: // Assets:Set team
    case 9233: // Assets:Set metadata
    case 9234: // Assets:Clear metadata
    case 9235: // Assets:Force set metadata
    case 9236: // Assets:Force clear metadata
    case 9237: // Assets:Force asset status
    case 9238: // Assets:Approve transfer
    case 9239: // Assets:Cancel approval
    case 9240: // Assets:Force cancel approval
    case 9241: // Assets:Transfer approved
    case 9242: // Assets:Touch
    case 9243: // Assets:Refund
    case 9244: // Assets:Set min balance
    case 9245: // Assets:Touch other
    case 9246: // Assets:Refund other
    case 9247: // Assets:Block
        return false;
    default:
        return true;
    }
}
