//  Copyright 2018 Benjamin Bader
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.

#ifndef CPPMETRICS_METRICS_MANUALCLOCK_H
#define CPPMETRICS_METRICS_MANUALCLOCK_H

#include <metrics/Clock.h>

namespace cppmetrics {

class ManualClock : public Clock
{
public:
  ManualClock(const std::chrono::nanoseconds& now = std::chrono::nanoseconds(0));

  std::chrono::nanoseconds tick() override;
  time_t now_as_time_t() override;

  void add_nanos(long long nanos);
  void add_millis(int millis);
  void add_seconds(int seconds);
  void add_minutes(int minutes);
  void add_hours(int hours);

private:
  std::chrono::nanoseconds m_now;
};

}

#endif
