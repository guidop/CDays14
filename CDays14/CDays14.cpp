#include "stdafx.h"
#include <iostream>
#include <map>
#include <string>
#include <chrono>
#include <thread>
#include <mutex>

//#pragma warning (once:4702)
using namespace std;
std::mutex g_pages_mutex;
std::map<std::string, std::string> g_pages;

void save_page(const std::string &url, long aTime)
{
	// simulate a long page fetch

	std::string result = "testo";

	g_pages_mutex.lock();	
	std::this_thread::sleep_for(std::chrono::seconds(aTime));
	g_pages[url] = result;	
	g_pages_mutex.unlock();
}

int main()
{
	std::thread t1(save_page, "http://pippo", 2);
	std::thread t2(save_page, "http://pluto", 10);
	
	t1.join();
	t2.join();
	
	
	for (const auto &pair : g_pages) {
		std::cout << pair.first << " => " << pair.second << '\n';
	}
}