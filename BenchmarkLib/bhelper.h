#pragma once

#include <numeric>
#include <vector>

namespace bcpp
{
	template <typename T>
	T min(const std::vector<T>& vec)
	{
		return *std::min_element(vec.begin(), vec.end());
	}

	template <typename T>
	T max(const std::vector<T>& vec)
	{
		*std::max_element(vec.begin(), vec.end());
	}

	template <typename T>
	T mean(const std::vector<T>& vec)
	{
		return std::accumulate(vec.begin(), vec.end(), default(T)) / vec.size();
	}

	template <typename T>
	T median(const std::vector<T>& vec)
	{
		std::vector<T> sorted(vec);
		std::sort(sorted.begin(), sorted.end());
		return sorted[sorted.size() / 2];
	}

	template <typename T>
	T sd(const std::vector<T>& vec)
	{
		T m = mean(vec);
		T sum = std::accumulate(vec.begin(), vec.end(), 0.0, [m](T a, T b) { return a + (b - m) * (b - m); });
		return std::sqrt(sum / vec.size());
	}

}