
#include "../include/utils.h"

//TODO: test these

double utils_mean(std::vector<double> v){
	// Calculate mean...
	double sum = std::accumulate(v.begin(),v.end(),0.0);
	double mean = sum / v.size();
	return mean;
}


double utils_stddev(std::vector<double> v){
	double mean = utils_mean(v);
	// Standard Deviation magic...
	std::vector<double> diff(v.size());
	std::transform(v.begin(), v.end(), diff.begin(),std::bind2nd(std::minus<double>(), mean));
	double sq_sum = std::inner_product(diff.begin(), diff.end(), diff.begin(), 0.0);
	double stdev = std::sqrt(sq_sum / v.size()); 
	return stdev;
}