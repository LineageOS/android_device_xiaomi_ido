/*
 * Copyright (C) 2016 The CyanogenMod Project
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

package org.cyanogenmod.hardware;

import org.cyanogenmod.internal.util.FileUtils;

import java.io.File;

/*
 * Disable capacitive keys
 *
 * This is intended for use on devices in which the capacitive keys
 * can be fully disabled for replacement with a soft navbar. You
 * really should not be using this on a device with mechanical or
 * otherwise visible-when-inactive keys
 */

public class KeyDisabler {

    // Focaltech
    private static String CONTROL_PATH_FT = "/sys/devices/soc.0/78b9000.i2c/i2c-5/5-003e/disable_keys";

    // Imagis
    private static String CONTROL_PATH_IST = "/sys/devices/soc.0/78b9000.i2c/i2c-5/5-0050/disable_keys";

    private static String KeyDisabler_path() {
        File ft = new File(CONTROL_PATH_FT);
        File ist = new File(CONTROL_PATH_IST);
        if (ft.exists()) {
            return CONTROL_PATH_FT;
        } else {
            return CONTROL_PATH_IST;
        }
    };

    public static boolean isSupported() {
       return FileUtils.isFileReadable(KeyDisabler_path()) &&
                FileUtils.isFileWritable(KeyDisabler_path());
	}

    public static boolean isActive() {
        return "0".equals(FileUtils.readOneLine(KeyDisabler_path));
    }

    public static boolean setActive(boolean state) {
        return FileUtils.writeLine(KeyDisabler_path(), state ? "1" : "0");
    }
}
