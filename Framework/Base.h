#pragma once

#include <cstring>
#include <string>
#include <ctime>
#include <atomic>
#include <memory>
#include <chrono>
#include <mutex>
#include <unordered_map>
#include <stack>
#include <vector>
#include <list>
#include <queue>
#include <set>
#include <algorithm>
#include <future>
#include <thread>
#include <fstream>
#include <sstream>
#include <cmath>
#include <stdarg.h>
#include <type_traits>
#include <functional>
#include <iostream>

class NonCopyable
{
protected:
	NonCopyable(void) = default;
	virtual ~NonCopyable(void) = default;
private:
	NonCopyable(const NonCopyable&) = delete;
	const NonCopyable& operator=(const NonCopyable&) = delete;
};

class Base : private NonCopyable
{
private:
	unsigned int _Serial;
	std::string _Name;
	
public:
	Base(void)
	{
		static unsigned int ui;
		_Serial = ui++;
		_Name = std::to_string(_Serial);
	}
	const unsigned int& Serial(void) const
	{
		return _Serial;
	}
	void SetName(const std::string& Name)
	{
		_Name = Name;
	}
	const std::string& GetName(void)
	{
		return _Name;
	}
};