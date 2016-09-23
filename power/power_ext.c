/*
 * Copyright (c) 2016 The CyanogenMod Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#define LOG_TAG "PowerHAL_MSM8939_Ext"

#include <utils/Log.h>
#include "utils.h"

#define BIG_CLUSTER_CTL_PATH "/sys/devices/system/cpu/cpu0/core_ctl/"
#define SMALL_CLUSTER_CTL_PATH "/sys/devices/system/cpu/cpu4/core_ctl/"

/**
 * If target is 8916:
 *     return 1
 * else:
 *     return 0
 */
static int is_target_8916(void)
{
    static int is_8916 = -1;
    int soc_id;

    if (is_8916 >= 0)
        return is_8916;

    soc_id = get_soc_id();
    if (soc_id == 206 || (soc_id >= 247 && soc_id <= 250))
        is_8916 = 1;
    else
        is_8916 = 0;

    return is_8916;
}

void cm_power_set_interactive_ext(int on)
{
    if (!is_target_8916()) {
        ALOGD("%s low power mode", on ? "Disabling" : "Enabling");
        sysfs_write(BIG_CLUSTER_CTL_PATH "max_cpus", on ? "4" : "0");
        sysfs_write(BIG_CLUSTER_CTL_PATH "min_cpus", on ? "4" : "0");
        sysfs_write(SMALL_CLUSTER_CTL_PATH "min_cpus", on ? "0" : "4");
    }
}
