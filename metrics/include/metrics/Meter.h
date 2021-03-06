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

#ifndef CPPMETRICS_METRICS_METER_H
#define CPPMETRICS_METRICS_METER_H

#include <atomic>
#include <chrono>
#include <memory>

namespace cppmetrics {

class Clock;
class EWMA;

class Meter
{
public:
  Meter(Clock* clock = nullptr);

  void mark(long n = 1);

  long get_count() const noexcept;
  double get_m15_rate();
  double get_m5_rate();
  double get_m1_rate();
  double get_mean_rate();

private:
  void tick_if_necessary();

private:
  Clock* m_clock;

  std::atomic_long m_count;
  std::chrono::nanoseconds m_start_time;
  std::atomic_llong m_last_tick;

  std::shared_ptr<EWMA> m_m1;
  std::shared_ptr<EWMA> m_m5;
  std::shared_ptr<EWMA> m_m15;
};

}

#endif
