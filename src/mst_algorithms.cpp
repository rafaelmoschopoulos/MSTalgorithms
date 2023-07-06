#include <iostream>
#include "algorithms.h"
#include "graphutils.h"
#include "csvfile.h"
#include <chrono>
#include <iomanip>
using time_point = std::chrono::system_clock::time_point;
std::string serializeTimePoint(const time_point& time, const std::string& format)
{
	std::time_t tt = std::chrono::system_clock::to_time_t(time);
	std::tm tm = *std::localtime(&tt); //Locale time-zone, usually UTC by default.
	std::stringstream ss;
	ss << std::put_time(&tm, format.c_str());
	return ss.str();
}
#define PATH "../data/"
int main()
{
	try {
		time_point input = std::chrono::system_clock::now();
		auto filename = serializeTimePoint(input, "%d%m%y_%H%M%S");
		csvfile csv(PATH+filename+".csv");
		csv << "V" << "E" << "d" << "MAX_W" << "Kruskals" << "Prims" << "Boruvkas" << endrow;

/*

		constexpr long long nNodes = 40000;
		constexpr int max_weight = 10;
		for (float density = 0.0001; density <= 0.01f; density += 0.0001f) {
			long nEdges = density * nNodes * (nNodes - 1) / 2;
			long long time_graphs, time_kruskals, time_prims_bin, time_boruvkas;
			auto edges = randomGraph(nEdges, nNodes, time_graphs, max_weight);

			kruskals(edges, nNodes, time_kruskals);
			prims_bin(edges, nNodes, time_prims_bin);
			boruvkas(edges, nNodes, time_boruvkas);
			std::cout << "V = " << nNodes << ", E = " << nEdges << ", d = " << density << ", max(w) = " << max_weight << "\n"
				<< "Random graph generator: " << time_graphs
				<< " ms\nKruskals: " << time_kruskals
				<< " ms\nPrims (binary heap): " << time_prims_bin
				<< " ms\nBoruvkas: " << time_boruvkas << " ms\n"
				<< "--------------------------\n\n";
			csv << nNodes << nEdges << density*100 << max_weight << time_kruskals << time_prims_bin << time_boruvkas << endrow;
		}*/
/*
		constexpr long long nEdges = 10000000;
		int min_nNodes = std::floor(1 + std::sqrt(1 + 8 * nEdges) / 2);
		constexpr int max_weight = 10;
		for (int nNodes = 50000; nNodes < 100000; nNodes += 5000) {
			float density = 2 * nEdges / (nNodes * (nNodes - 1));
			long long time_graphs, time_kruskals, time_prims_bin, time_boruvkas;
			auto edges = randomGraph(nEdges, nNodes, time_graphs, max_weight);

			kruskals(edges, nNodes, time_kruskals);
			prims_bin(edges, nNodes, time_prims_bin);
			boruvkas(edges, nNodes, time_boruvkas);
			std::cout << "V = " << nNodes << ", E = " << nEdges << ", d = " << density << ", max(w) = " << max_weight << "\n"
				<< "Random graph generator: " << time_graphs
				<< " ms\nKruskals: " << time_kruskals
				<< " ms\nPrims (binary heap): " << time_prims_bin
				<< " ms\nBoruvkas: " << time_boruvkas << " ms\n"
				<< "--------------------------\n\n";
			//csv << nNodes << nEdges << density*100 << max_weight << time_kruskals << time_prims_bin << time_boruvkas << endrow;
		}*/
		/*
		constexpr long long nNodes = 40000;
		for (int max_weight = 10; max_weight <= 10000; max_weight+=100) {
			float density = 0.01;
			long nEdges = density * nNodes * (nNodes - 1) / 2;
			long long time_graphs, time_kruskals, time_prims_bin, time_boruvkas;
			auto edges = randomGraph(nEdges, nNodes, time_graphs, max_weight);

			kruskals(edges, nNodes, time_kruskals);
			prims_bin(edges, nNodes, time_prims_bin);
			boruvkas(edges, nNodes, time_boruvkas);
			std::cout << "V = " << nNodes << ", E = " << nEdges << ", max(w) = " << max_weight << "\n"
				<< "Random graph generator: " << time_graphs
				<< " ms\nKruskals: " << time_kruskals
				<< " ms\nPrims (binary heap): " << time_prims_bin
				<< " ms\nBoruvkas: " << time_boruvkas << " ms\n"
				<< "--------------------------\n\n";
			csv << nNodes << nEdges << density << max_weight << time_kruskals << time_prims_bin << time_boruvkas << endrow;
		}*/
		constexpr long long nNodes = 40000;
		int max_weight = 10000;
		float density = 0.01;
		long nEdges = density * nNodes * (nNodes - 1) / 2;
		long long time_graphs, time_kruskals, time_prims_bin, time_boruvkas;
		auto edges = randomGraph(nEdges, nNodes, time_graphs, max_weight);

		for (int i = 0; i != 100; i++) {
			kruskals(edges, nNodes, time_kruskals);
			prims_bin(edges, nNodes, time_prims_bin);
			boruvkas(edges, nNodes, time_boruvkas);
			std::cout << "V = " << nNodes << ", E = " << nEdges << ", max(w) = " << max_weight << "\n"
				<< "Random graph generator: " << time_graphs
				<< " ms\nKruskals: " << time_kruskals
				<< " ms\nPrims (binary heap): " << time_prims_bin
				<< " ms\nBoruvkas: " << time_boruvkas << " ms\n"
				<< "--------------------------\n\n";
			csv << nNodes << nEdges << density << max_weight << time_kruskals << time_prims_bin << time_boruvkas << endrow;
		}


	}
	catch(std::runtime_error& re)
	{
		std::cout << re.what() << '\n';
	}
	return 0;
}