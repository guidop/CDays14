#include "stdafx.h"
#include <iostream>
#include <map>
#include <string>
#include <chrono>
#include <thread>
#include <mutex>

using namespace std;
std::mutex g_pages_mutex;
std::map<std::string, std::string> g_pages;


void save_page(const std::string &url, int aTime)
{
	// simulate a long page fetch

	std::string result = "fake content";

	g_pages_mutex.lock(); // or, to be exception-safe, use std::lock_guard
	std::this_thread::sleep_for(std::chrono::seconds(aTime));
	g_pages[url] = result;	
	g_pages_mutex.unlock();

	
}

int main()
{
	std::thread t2(save_page, "http://foo", 10);
	std::thread t1(save_page, "http://bar", 17);
	
	t2.join();

	t1.join();
	
	
	


	// safe to access g_pages without lock now, as the threads are joined
	for (const auto &pair : g_pages) {
		std::cout << pair.first << " => " << pair.second << '\n';
	}


}