#pragma once
using namespace System;
namespace Project2 {
	value class Teste
	{
	private:
		int lap;
		String^ boot;
	public:
		//Teste();
		Teste(String^ nom, int lap);
		virtual String^ ToString() override {
			return boot + " : " + lap;
		}
	};
}

