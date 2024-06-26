# Ledger Astar App

[![License](https://img.shields.io/badge/License-Apache%202.0-blue.svg)](https://opensource.org/licenses/Apache-2.0)
[![GithubActions](https://github.com/zondax/ledger-astar/actions/workflows/main.yml/badge.svg)](https://github.com/Zondax/ledger-astar/blob/main/.github/workflows/main.yaml)

---

![zondax_light](docs/zondax_light.png#gh-light-mode-only)
![zondax_dark](docs/zondax_dark.png#gh-dark-mode-only)

_Please visit our website at [zondax.ch](https://www.zondax.ch)_

---

This project contains the Astar app (https://astar.network/) for Ledger Nano S and X.

- Ledger Nano S/X BOLOS app
- Specs / Documentation
- C++ unit tests
- Zemu tests

For more information: [How to build](docs/build.md)

## ATTENTION

Please:

- **Do not use in production**
- **Do not use a Ledger device with funds for development purposes.**
- **Have a separate and marked device that is used ONLY for development and testing**
# Astar 2.83.x

## System

| Name                    | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                         |
| ----------------------- | ------ | ------------------ | ------------------ | ------------------ | --------------------------------- |
| Remark                  |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Bytes`remark<br/>                |
| Set heap pages          |        |                    |                    |                    | `u64`pages<br/>                   |
| Set code                |        |                    |                    |                    | `Vecu8`code<br/>                  |
| Set code without checks |        |                    |                    |                    | `Vecu8`code<br/>                  |
| Set storage             |        |                    |                    |                    | `VecKeyValue`items<br/>           |
| Kill storage            |        |                    |                    |                    | `VecKey`keys<br/>                 |
| Kill prefix             |        |                    |                    |                    | `Key`prefix<br/>`u32`subkeys<br/> |
| Remark with event       |        |                    |                    |                    | `Bytes`remark<br/>                |

## Utility

| Name          | Nano S             | Nano S XL          | Nano SP/X - Stax   | Nesting | Arguments                                       |
| ------------- | ------------------ | ------------------ | ------------------ | ------- | ----------------------------------------------- |
| Batch         | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `VecCall`calls<br/>                             |
| As derivative |                    |                    |                    |         | `u16`index<br/>`Call`call<br/>                  |
| Batch all     | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `VecCall`calls<br/>                             |
| Dispatch as   |                    |                    |                    |         | `BoxPalletsOrigin`as_origin<br/>`Call`call<br/> |
| Force batch   | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `VecCall`calls<br/>                             |
| With weight   |                    | :heavy_check_mark: | :heavy_check_mark: |         | `Call`call<br/>`Weight`weight<br/>              |

## Identity

| Name              | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                                       |
| ----------------- | ------ | --------- | ---------------- | ------- | --------------------------------------------------------------------------------------------------------------- |
| Add registrar     |        |           |                  |         | `AccountIdLookupOfT`account<br/>                                                                                |
| Set identity      |        |           |                  |         | `IdentityInfo`info<br/>                                                                                         |
| Set subs          |        |           |                  |         | `VecTupleAccountIdData`subs<br/>                                                                                |
| Clear identity    |        |           |                  |         |                                                                                                                 |
| Request judgement |        |           |                  |         | `Compactu32`reg_index<br/>`Compactu128`max_fee<br/>                                                             |
| Cancel request    |        |           |                  |         | `RegistrarIndex`reg_index<br/>                                                                                  |
| Set fee           |        |           |                  |         | `Compactu32`index<br/>`Compactu128`fee<br/>                                                                     |
| Set account id    |        |           |                  |         | `Compactu32`index<br/>`AccountIdLookupOfT`new\_<br/>                                                            |
| Set fields        |        |           |                  |         | `Compactu32`index<br/>`IdentityFields`fields<br/>                                                               |
| Provide judgement |        |           |                  |         | `Compactu32`reg_index<br/>`AccountIdLookupOfT`target<br/>`JudgementBalanceOfT`judgement<br/>`Hash`identity<br/> |
| Kill identity     |        |           |                  |         | `AccountIdLookupOfT`target<br/>                                                                                 |
| Add sub           |        |           |                  |         | `AccountIdLookupOfT`sub<br/>`Data`data<br/>                                                                     |
| Rename sub        |        |           |                  |         | `AccountIdLookupOfT`sub<br/>`Data`data<br/>                                                                     |
| Remove sub        |        |           |                  |         | `AccountIdLookupOfT`sub<br/>                                                                                    |
| Quit sub          |        |           |                  |         |                                                                                                                 |

## Timestamp

| Name | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments            |
| ---- | ------ | --------- | ---------------- | ------- | -------------------- |
| Set  |        |           |                  |         | `Compactu64`now<br/> |

## Multisig

| Name                 | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                                                                                                                               |
| -------------------- | ------ | ------------------ | ------------------ | ------------------ | --------------------------------------------------------------------------------------------------------------------------------------- |
| As multi threshold 1 |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `VecAccountId`other_signatories<br/>`Call`call<br/>                                                                                     |
| As multi             |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `u16`threshold<br/>`VecAccountId`other_signatories<br/>`OptionTimepoint`maybe_timepoint<br/>`Call`call<br/>`Weight`max_weight<br/>      |
| Approve as multi     |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `u16`threshold<br/>`VecAccountId`other_signatories<br/>`OptionTimepoint`maybe_timepoint<br/>`H256`call_hash<br/>`Weight`max_weight<br/> |
| Cancel as multi      |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `u16`threshold<br/>`VecAccountId`other_signatories<br/>`Timepoint`timepoint<br/>`H256`call_hash<br/>                                    |

## Proxy

| Name                | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                                                                                                                  |
| ------------------- | ------ | ------------------ | ------------------ | ------------------ | -------------------------------------------------------------------------------------------------------------------------- |
| Proxy               |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`real<br/>`OptionProxyType`force_proxy_type<br/>`Call`call<br/>                                         |
| Add proxy           |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`delegate<br/>`ProxyType`proxy_type<br/>`BlockNumber`delay<br/>                                         |
| Remove proxy        |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`delegate<br/>`ProxyType`proxy_type<br/>`BlockNumber`delay<br/>                                         |
| Remove proxies      |        | :heavy_check_mark: | :heavy_check_mark: |                    |                                                                                                                            |
| Create pure         |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `ProxyType`proxy_type<br/>`BlockNumber`delay<br/>`u16`index<br/>                                                           |
| Kill pure           |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`spawner<br/>`ProxyType`proxy_type<br/>`u16`index<br/>`Compactu32`height<br/>`Compactu32`ext_index<br/> |
| Announce            |        | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountIdLookupOfT`real<br/>`CallHashOf`call_hash<br/>                                                                    |
| Remove announcement |        | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountIdLookupOfT`real<br/>`CallHashOf`call_hash<br/>                                                                    |
| Reject announcement |        | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountIdLookupOfT`delegate<br/>`CallHashOf`call_hash<br/>                                                                |
| Proxy announced     |        | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountIdLookupOfT`delegate<br/>`AccountIdLookupOfT`real<br/>`OptionProxyType`force_proxy_type<br/>`Call`call<br/>        |

## ParachainSystem

| Name                     | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                    |
| ------------------------ | ------ | --------- | ---------------- | ------- | -------------------------------------------- |
| Set validation data      |        |           |                  |         | `ParachainInherentData`data<br/>             |
| Sudo send upward message |        |           |                  |         | `UpwardMessage`message<br/>                  |
| Authorize upgrade        |        |           |                  |         | `Hash`code_hash<br/>`bool`check_version<br/> |
| Enact authorized upgrade |        |           |                  |         | `Vecu8`code<br/>                             |

## ParachainInfo

| Name | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments |
| ---- | ------ | --------- | ---------------- | ------- | --------- |

## Balances

| Name                   | Nano S             | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                                                                                  |
| ---------------------- | ------------------ | ------------------ | ------------------ | ------------------ | ------------------------------------------------------------------------------------------ |
| Transfer allow death   | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`dest<br/>`CompactBalance`amount<br/>                                   |
| Set balance deprecated |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`who<br/>`CompactBalance`new_free<br/>`CompactBalance`old_reserved<br/> |
| Force transfer         | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`source<br/>`AccountIdLookupOfT`dest<br/>`CompactBalance`amount<br/>    |
| Transfer keep alive    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`dest<br/>`CompactBalance`amount<br/>                                   |
| Transfer all           | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`dest<br/>`bool`keep_alive<br/>                                         |
| Force unreserve        |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountIdLookupOfT`who<br/>`Balance`amount<br/>                                           |
| Upgrade accounts       |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `VecAccountId`who<br/>                                                                     |
| Transfer               | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`dest<br/>`CompactBalance`amount<br/>                                   |
| Force set balance      |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountIdLookupOfT`who<br/>`CompactBalance`new_free<br/>                                  |

## Vesting

| Name                  | Nano S             | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                                                                                |
| --------------------- | ------------------ | ------------------ | ------------------ | ------------------ | ---------------------------------------------------------------------------------------- |
| Vest                  | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |                                                                                          |
| Vest other            | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`target<br/>                                                          |
| Vested transfer       | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`target<br/>`VestingInfo`schedule<br/>                                |
| Force vested transfer | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`source<br/>`AccountIdLookupOfT`target<br/>`VestingInfo`schedule<br/> |
| Merge schedules       | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `u32`schedule1_index<br/>`u32`schedule2_index<br/>                                       |

## Inflation

| Name                          | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                        |
| ----------------------------- | ------ | --------- | ---------------- | ------- | -------------------------------- |
| Force set inflation params    |        |           |                  |         | `InflationParameters`params<br/> |
| Force inflation recalculation |        |           |                  |         | `EraNumber`next_era<br/>         |

## DappStaking

| Name                        | Nano S             | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                                                           |
| --------------------------- | ------------------ | ------------------ | ------------------ | ------------------ | ------------------------------------------------------------------- |
| Unbond and unstake          | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `SmartContract`contract_id<br/>`Compactu128`amount<br/>             |
| Withdraw Unbonded           | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |                                                                     |
| Maintenance mode            | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `bool`enabled<br/>                                                  |
| Register                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountId`owner<br/>`SmartContract`smart_contract<br/>             |
| Set dapp reward beneficiary | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `SmartContract`smart_contract<br/>`OptionAccountId`beneficiary<br/> |
| Set dapp owner              | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `SmartContract`smart_contract<br/>`AccountId`new_owner<br/>         |
| Unregister                  | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `SmartContract`smart_contract<br/>                                  |
| Lock                        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Compactu128`amount<br/>                                            |
| Unlock                      | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Compactu128`amount<br/>                                            |
| Claim unlocked              | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |                                                                     |
| Relock unlocking            | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |                                                                     |
| Stake                       | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `SmartContract`smart_contract<br/>`Compactu128`amount<br/>          |
| Unstake                     | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `SmartContract`smart_contract<br/>`Compactu128`amount<br/>          |
| Claim staker rewards        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |                                                                     |
| Claim bonus reward          | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `SmartContract`smart_contract<br/>                                  |
| Claim dapp reward           | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `SmartContract`smart_contract<br/>`Compactu32`era<br/>              |
| Unstake from unregistered   | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `SmartContract`smart_contract<br/>                                  |
| Cleanup expired entries     | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |                                                                     |
| Force                       |                    |                    |                    |                    | `ForcingType`forcing_type<br/>                                      |

## Assets

| Name                  | Nano S | Nano S XL          | Nano SP/X - Stax   | Nesting | Arguments                                                                                                                                                                                                                      |
| --------------------- | ------ | ------------------ | ------------------ | ------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| Create                |        | :heavy_check_mark: | :heavy_check_mark: |         | `CompactBalance`id<br/>`AccountIdLookupOfT`admin<br/>`Balance`min_balance<br/>                                                                                                                                                 |
| Force create          |        | :heavy_check_mark: | :heavy_check_mark: |         | `CompactBalance`id<br/>`AccountIdLookupOfT`owner<br/>`bool`is_sufficient<br/>`CompactBalance`min_balance<br/>                                                                                                                  |
| Start destroy         |        | :heavy_check_mark: | :heavy_check_mark: |         | `CompactBalance`id<br/>                                                                                                                                                                                                        |
| Destroy accounts      |        | :heavy_check_mark: | :heavy_check_mark: |         | `CompactBalance`id<br/>                                                                                                                                                                                                        |
| Destroy approvals     |        | :heavy_check_mark: | :heavy_check_mark: |         | `CompactBalance`id<br/>                                                                                                                                                                                                        |
| Finish destroy        |        | :heavy_check_mark: | :heavy_check_mark: |         | `CompactBalance`id<br/>                                                                                                                                                                                                        |
| Mint                  |        | :heavy_check_mark: | :heavy_check_mark: |         | `CompactBalance`id<br/>`AccountIdLookupOfT`beneficiary<br/>`CompactBalance`amount<br/>                                                                                                                                         |
| Burn                  |        | :heavy_check_mark: | :heavy_check_mark: |         | `CompactBalance`id<br/>`AccountIdLookupOfT`who<br/>`CompactBalance`amount<br/>                                                                                                                                                 |
| Transfer              |        | :heavy_check_mark: | :heavy_check_mark: |         | `CompactBalance`id<br/>`AccountIdLookupOfT`target<br/>`CompactBalance`amount<br/>                                                                                                                                              |
| Transfer keep alive   |        | :heavy_check_mark: | :heavy_check_mark: |         | `CompactBalance`id<br/>`AccountIdLookupOfT`target<br/>`CompactBalance`amount<br/>                                                                                                                                              |
| Force transfer        |        | :heavy_check_mark: | :heavy_check_mark: |         | `CompactBalance`id<br/>`AccountIdLookupOfT`source<br/>`AccountIdLookupOfT`dest<br/>`CompactBalance`amount<br/>                                                                                                                 |
| Freeze                |        | :heavy_check_mark: | :heavy_check_mark: |         | `CompactBalance`id<br/>`AccountIdLookupOfT`who<br/>                                                                                                                                                                            |
| Thaw                  |        | :heavy_check_mark: | :heavy_check_mark: |         | `CompactBalance`id<br/>`AccountIdLookupOfT`who<br/>                                                                                                                                                                            |
| Freeze asset          |        | :heavy_check_mark: | :heavy_check_mark: |         | `CompactBalance`id<br/>                                                                                                                                                                                                        |
| Thaw asset            |        | :heavy_check_mark: | :heavy_check_mark: |         | `CompactBalance`id<br/>                                                                                                                                                                                                        |
| Transfer ownership    |        | :heavy_check_mark: | :heavy_check_mark: |         | `CompactBalance`id<br/>`AccountIdLookupOfT`owner<br/>                                                                                                                                                                          |
| Set team              |        | :heavy_check_mark: | :heavy_check_mark: |         | `CompactBalance`id<br/>`AccountIdLookupOfT`issuer<br/>`AccountIdLookupOfT`admin<br/>`AccountIdLookupOfT`freezer<br/>                                                                                                           |
| Set metadata          |        | :heavy_check_mark: | :heavy_check_mark: |         | `CompactBalance`id<br/>`Vecu8`name<br/>`Vecu8`symbol<br/>`u8`decimals<br/>                                                                                                                                                     |
| Clear metadata        |        | :heavy_check_mark: | :heavy_check_mark: |         | `CompactBalance`id<br/>                                                                                                                                                                                                        |
| Force set metadata    |        | :heavy_check_mark: | :heavy_check_mark: |         | `CompactBalance`id<br/>`Vecu8`name<br/>`Vecu8`symbol<br/>`u8`decimals<br/>`bool`is_frozen<br/>                                                                                                                                 |
| Force clear metadata  |        | :heavy_check_mark: | :heavy_check_mark: |         | `CompactBalance`id<br/>                                                                                                                                                                                                        |
| Force asset status    |        | :heavy_check_mark: | :heavy_check_mark: |         | `CompactBalance`id<br/>`AccountIdLookupOfT`owner<br/>`AccountIdLookupOfT`issuer<br/>`AccountIdLookupOfT`admin<br/>`AccountIdLookupOfT`freezer<br/>`CompactBalance`min_balance<br/>`bool`is_sufficient<br/>`bool`is_frozen<br/> |
| Approve transfer      |        | :heavy_check_mark: | :heavy_check_mark: |         | `CompactBalance`id<br/>`AccountIdLookupOfT`delegate<br/>`CompactBalance`amount<br/>                                                                                                                                            |
| Cancel approval       |        | :heavy_check_mark: | :heavy_check_mark: |         | `CompactBalance`id<br/>`AccountIdLookupOfT`delegate<br/>                                                                                                                                                                       |
| Force cancel approval |        | :heavy_check_mark: | :heavy_check_mark: |         | `CompactBalance`id<br/>`AccountIdLookupOfT`owner<br/>`AccountIdLookupOfT`delegate<br/>                                                                                                                                         |
| Transfer approved     |        | :heavy_check_mark: | :heavy_check_mark: |         | `CompactBalance`id<br/>`AccountIdLookupOfT`owner<br/>`AccountIdLookupOfT`destination<br/>`CompactBalance`amount<br/>                                                                                                           |
| Touch                 |        | :heavy_check_mark: | :heavy_check_mark: |         | `CompactBalance`id<br/>                                                                                                                                                                                                        |
| Refund                |        | :heavy_check_mark: | :heavy_check_mark: |         | `CompactBalance`id<br/>`bool`allow_burn<br/>                                                                                                                                                                                   |
| Set min balance       |        | :heavy_check_mark: | :heavy_check_mark: |         | `CompactBalance`id<br/>`Balance`min_balance<br/>                                                                                                                                                                               |
| Touch other           |        | :heavy_check_mark: | :heavy_check_mark: |         | `CompactBalance`id<br/>`AccountIdLookupOfT`who<br/>                                                                                                                                                                            |
| Refund other          |        | :heavy_check_mark: | :heavy_check_mark: |         | `CompactBalance`id<br/>`AccountIdLookupOfT`who<br/>                                                                                                                                                                            |
| Block                 |        | :heavy_check_mark: | :heavy_check_mark: |         | `CompactBalance`id<br/>`AccountIdLookupOfT`who<br/>                                                                                                                                                                            |

## CollatorSelection

| Name                   | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                |
| ---------------------- | ------ | --------- | ---------------- | ------- | ------------------------ |
| Set invulnerables      |        |           |                  |         | `VecAccountId`new\_<br/> |
| Set desired candidates |        |           |                  |         | `u32`max<br/>            |
| Set candidacy bond     |        |           |                  |         | `Balance`bond<br/>       |
| Register as candidate  |        |           |                  |         |                          |
| Leave intent           |        |           |                  |         |                          |

## Session

| Name       | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                        |
| ---------- | ------ | --------- | ---------------- | ------- | -------------------------------- |
| Set keys   |        |           |                  |         | `Keys`keys<br/>`Bytes`proof<br/> |
| Purge keys |        |           |                  |         |                                  |

## XcmpQueue

| Name                              | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                            |
| --------------------------------- | ------ | --------- | ---------------- | ------- | ---------------------------------------------------- |
| Service overweight                |        |           |                  |         | `OverweightIndex`index<br/>`Weight`weight_limit<br/> |
| Suspend xcm execution             |        |           |                  |         |                                                      |
| Resume xcm execution              |        |           |                  |         |                                                      |
| Update suspend threshold          |        |           |                  |         | `u32`new\_<br/>                                      |
| Update drop threshold             |        |           |                  |         | `u32`new\_<br/>                                      |
| Update resume threshold           |        |           |                  |         | `u32`new\_<br/>                                      |
| Update threshold weight           |        |           |                  |         | `Weight`new\_<br/>                                   |
| Update weight restrict decay      |        |           |                  |         | `Weight`new\_<br/>                                   |
| Update xcmp max individual weight |        |           |                  |         | `Weight`new\_<br/>                                   |

## PolkadotXcm

| Name                             | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                                                                                                 |
| -------------------------------- | ------ | --------- | ---------------- | ------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Send                             |        |           |                  |         | `BoxVersionedMultiLocation`dest<br/>`BoxVersionedXcmTuple`message<br/>                                                                                                    |
| Teleport assets                  |        |           |                  |         | `BoxVersionedMultiLocation`dest<br/>`BoxVersionedMultiLocation`beneficiary<br/>`BoxVersionedMultiAssets`assets<br/>`u32`fee_asset_item<br/>                               |
| Reserve transfer assets          |        |           |                  |         | `BoxVersionedMultiLocation`dest<br/>`BoxVersionedMultiLocation`beneficiary<br/>`BoxVersionedMultiAssets`assets<br/>`u32`fee_asset_item<br/>                               |
| Execute                          |        |           |                  |         | `BoxVersionedXcmTasSysConfigRuntimeCall`message<br/>`Weight`max_weight<br/>                                                                                               |
| Force xcm version                |        |           |                  |         | `BoxMultiLocation`location<br/>`XcmVersion`version<br/>                                                                                                                   |
| Force default xcm version        |        |           |                  |         | `OptionXcmVersion`maybe_xcm_version<br/>                                                                                                                                  |
| Force subscribe version notify   |        |           |                  |         | `BoxVersionedMultiLocation`location<br/>                                                                                                                                  |
| Force unsubscribe version notify |        |           |                  |         | `BoxVersionedMultiLocation`location<br/>                                                                                                                                  |
| Limited reserve transfer assets  |        |           |                  |         | `BoxVersionedMultiLocation`dest<br/>`BoxVersionedMultiLocation`beneficiary<br/>`BoxVersionedMultiAssets`assets<br/>`u32`fee_asset_item<br/>`WeightLimit`weight_limit<br/> |
| Limited teleport assets          |        |           |                  |         | `BoxVersionedMultiLocation`dest<br/>`BoxVersionedMultiLocation`beneficiary<br/>`BoxVersionedMultiAssets`assets<br/>`u32`fee_asset_item<br/>`WeightLimit`weight_limit<br/> |
| Force suspension                 |        |           |                  |         | `bool`suspended<br/>                                                                                                                                                      |

## CumulusXcm

| Name | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments |
| ---- | ------ | --------- | ---------------- | ------- | --------- |

## DmpQueue

| Name               | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                            |
| ------------------ | ------ | --------- | ---------------- | ------- | ---------------------------------------------------- |
| Service overweight |        |           |                  |         | `OverweightIndex`index<br/>`Weight`weight_limit<br/> |

## XcAssetConfig

| Name                           | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                        |
| ------------------------------ | ------ | --------- | ---------------- | ------- | -------------------------------------------------------------------------------- |
| Register asset location        |        |           |                  |         | `BoxVersionedMultiLocation`asset_location<br/>`Compactu128`asset_id<br/>         |
| Set asset units per second     |        |           |                  |         | `BoxVersionedMultiLocation`asset_location<br/>`Compactu128`units_per_second<br/> |
| Change existing asset location |        |           |                  |         | `BoxVersionedMultiLocation`new_asset_location<br/>`Compactu128`asset_id<br/>     |
| Remove payment asset           |        |           |                  |         | `BoxVersionedMultiLocation`asset_location<br/>                                   |
| Remove asset                   |        |           |                  |         | `Compactu128`asset_id<br/>                                                       |

## XTokens

| Name                         | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                                                                 |
| ---------------------------- | ------ | --------- | ---------------- | ------- | ----------------------------------------------------------------------------------------------------------------------------------------- |
| Transfer                     |        |           |                  |         | `CurrencyId`currency_id<br/>`Balance`amount<br/>`BoxVersionedMultiLocation`dest<br/>`WeightLimit`dest_weight_limit<br/>                   |
| Transfer multiasset          |        |           |                  |         | `BoxVersionedMultiAsset`asset<br/>`BoxVersionedMultiLocation`dest<br/>`WeightLimit`dest_weight_limit<br/>                                 |
| Transfer with fee            |        |           |                  |         | `CurrencyId`currency_id<br/>`Balance`amount<br/>`Balance`fee<br/>`BoxVersionedMultiLocation`dest<br/>`WeightLimit`dest_weight_limit<br/>  |
| Transfer multiasset with fee |        |           |                  |         | `BoxVersionedMultiAsset`asset<br/>`BoxVersionedMultiAsset`fee<br/>`BoxVersionedMultiLocation`dest<br/>`WeightLimit`dest_weight_limit<br/> |
| Transfer multicurrencies     |        |           |                  |         | `VecTupleCurrencyIdBalance`currencies<br/>`u32`fee_item<br/>`BoxVersionedMultiLocation`dest<br/>`WeightLimit`dest_weight_limit<br/>       |
| Transfer multiassets         |        |           |                  |         | `BoxVersionedMultiAssets`assets<br/>`u32`fee_item<br/>`BoxVersionedMultiLocation`dest<br/>`WeightLimit`dest_weight_limit<br/>             |

## EVM

| Name     | Nano S             | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                                                                                                                                                                                                            |
| -------- | ------------------ | ------------------ | ------------------ | ------------------ | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Withdraw | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `H160`address<br/>`Balance`amount<br/>                                                                                                                                                                               |
| Call     |                    |                    |                    |                    | `H160`source<br/>`H160`target<br/>`Vecu8`input<br/>`U256`value<br/>`u64`gas_limit<br/>`U256`max_fee_per_gas<br/>`OptionU256`max_priority_fee_per_gas<br/>`OptionU256`nonce<br/>`VecTupleH160VecH256`access_list<br/> |
| Create   |                    |                    |                    |                    | `H160`source<br/>`Vecu8`init<br/>`U256`value<br/>`u64`gas_limit<br/>`U256`max_fee_per_gas<br/>`OptionU256`max_priority_fee_per_gas<br/>`OptionU256`nonce<br/>`VecTupleH160VecH256`access_list<br/>                   |
| Create2  |                    |                    |                    |                    | `H160`source<br/>`Vecu8`init<br/>`H256`salt<br/>`U256`value<br/>`u64`gas_limit<br/>`U256`max_fee_per_gas<br/>`OptionU256`max_priority_fee_per_gas<br/>`OptionU256`nonce<br/>`VecTupleH160VecH256`access_list<br/>    |

## Ethereum

| Name     | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                     |
| -------- | ------ | --------- | ---------------- | ------- | ----------------------------- |
| Transact |        |           |                  |         | `Transaction`transaction<br/> |

## DynamicEvmBaseFee

| Name                 | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments      |
| -------------------- | ------ | --------- | ---------------- | ------- | -------------- |
| Set base fee per gas |        |           |                  |         | `U256`fee<br/> |

## Contracts

| Name                             | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                                                                                                                                       |
| -------------------------------- | ------ | --------- | ---------------- | ------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Call old weight                  |        |           |                  |         | `AccountIdLookupOfT`dest<br/>`CompactBalance`amount<br/>`Compactu64`gas_limit<br/>`OptionCompactBalanceOf`storage_deposit_limit<br/>`Vecu8`data<br/>            |
| Instantiate with code old weight |        |           |                  |         | `CompactBalance`amount<br/>`Compactu64`gas_limit<br/>`OptionCompactBalanceOf`storage_deposit_limit<br/>`Vecu8`code<br/>`Vecu8`data<br/>`Vecu8`salt<br/>         |
| Instantiate old weight           |        |           |                  |         | `CompactBalance`amount<br/>`Compactu64`gas_limit<br/>`OptionCompactBalanceOf`storage_deposit_limit<br/>`CodeHash`code_hash<br/>`Vecu8`data<br/>`Vecu8`salt<br/> |
| Upload code                      |        |           |                  |         | `Vecu8`code<br/>`OptionCompactBalanceOf`storage_deposit_limit<br/>`Determinism`determinism<br/>                                                                 |
| Remove code                      |        |           |                  |         | `CodeHash`code_hash<br/>                                                                                                                                        |
| Set code                         |        |           |                  |         | `AccountIdLookupOfT`dest<br/>`CodeHash`code_hash<br/>                                                                                                           |
| Call                             |        |           |                  |         | `AccountIdLookupOfT`dest<br/>`CompactBalance`amount<br/>`Weight`gas_limit<br/>`OptionCompactBalanceOf`storage_deposit_limit<br/>`Vecu8`data<br/>                |
| Instantiate with code            |        |           |                  |         | `CompactBalance`amount<br/>`Weight`gas_limit<br/>`OptionCompactBalanceOf`storage_deposit_limit<br/>`Vecu8`code<br/>`Vecu8`data<br/>`Vecu8`salt<br/>             |
| Instantiate                      |        |           |                  |         | `CompactBalance`amount<br/>`Weight`gas_limit<br/>`OptionCompactBalanceOf`storage_deposit_limit<br/>`CodeHash`code_hash<br/>`Bytes`data<br/>`Bytes`salt<br/>     |
| Migrate                          |        |           |                  |         | `Weight`weight_limit<br/>                                                                                                                                       |

## Sudo

| Name                  | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments                                   |
| --------------------- | ------ | --------- | ---------------- | ------- | ------------------------------------------- |
| Sudo                  |        |           |                  |         | `Call`call<br/>                             |
| Sudo unchecked weight |        |           |                  |         | `Call`call<br/>`Weight`weight<br/>          |
| Set key               |        |           |                  |         | `AccountIdLookupOfT`new\_<br/>              |
| Sudo as               |        |           |                  |         | `AccountIdLookupOfT`who<br/>`Call`call<br/> |

## StaticPriceProvider

| Name            | Nano S | Nano S XL | Nano SP/X - Stax | Nesting | Arguments            |
| --------------- | ------ | --------- | ---------------- | ------- | -------------------- |
| Force set price |        |           |                  |         | `FixedU64`price<br/> |

## DappStakingMigration

| Name    | Nano S             | Nano S XL          | Nano SP/X - Stax   | Nesting            | Arguments                       |
| ------- | ------------------ | ------------------ | ------------------ | ------------------ | ------------------------------- |
| Migrate | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `OptionWeight`weight_limit<br/> |
