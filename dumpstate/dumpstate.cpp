/*
 * Copyright 2013 The Android Open Source Project
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

#include <dumpstate.h>

void dumpstate_board()
{
    Dumpstate& ds = Dumpstate::GetInstance();
    ds.DumpFile("INTERRUPTS", "/proc/interrupts");
    ds.DumpFile("Power Management Stats", "/proc/msm_pm_stats");
    ds.RunCommand("Subsystem Tombstone list", {"ls", "-l", "/data/tombstones/ramdump"}, CommandOptions::AS_ROOT_5);
    ds.DumpFile("BAM DMUX Log", "/d/ipc_logging/bam_dmux/log");
    ds.DumpFile("SMD Log", "/d/ipc_logging/smd/log");
    ds.DumpFile("SMD PKT Log", "/d/ipc_logging/smd_pkt/log");
    ds.DumpFile("IPC Router Log", "/d/ipc_logging/ipc_router/log");
    ds.RunCommand("ION HEAPS",   {"/system/bin/sh", "-c", "for f in $(ls /d/ion/heaps/*);   do echo $f; cat $f; done"}, CommandOptions::AS_ROOT_5);
    ds.DumpFile("RPM Master Stats", "/d/rpm_master_stats");
    ds.DumpFile("RPM stats", "/d/rpm_stats");
    ds.RunCommand("RPM log",   {"/system/bin/sh", "-c", "head -1024 /d/rpm_log"}, CommandOptions::AS_ROOT_5);
};
