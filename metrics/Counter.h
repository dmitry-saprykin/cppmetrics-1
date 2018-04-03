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

#ifndef CPPMETRICS_METRICS_COUNTER_H
#define CPPMETRICS_METRICS_COUNTER_H

#include <atomic>

namespace cppmetrics {

class Counter
{
public:
  Counter();
  Counter(const Counter&);
  Counter(Counter&&);

  Counter& operator=(const Counter&);
  Counter& operator=(Counter&&);

  void inc(long n = 1);
  void dec(long n = 1);

  long get_count() const noexcept;

private:
  std::atomic_long m_count;
};

} // namespace cppmetrics

#endif
