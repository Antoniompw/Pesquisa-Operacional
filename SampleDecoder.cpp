/*
 * SampleDecoder.cpp
 *
 * For more information, see SampleDecoder.h
 *
 * Created on : Nov 17, 2011 by rtoso
 * Authors    : Rodrigo Franco Toso <rtoso@cs.rutgers.edu>
 *              Mauricio G.C. Resende <mgcr@research.att.com>
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2018
 * Rodrigo Franco Toso (rfrancotoso@gmail.com) and
 * Mauricio G.C. Resende
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is furnished to do
 * so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

#include "SampleDecoder.h"
#include "instancia.h"
SampleDecoder::SampleDecoder() { }

SampleDecoder::~SampleDecoder() { }
// Runs in O(n \log n):
double SampleDecoder::decode(const std::vector< double >& chromosome) const {
	double myFitness = 0.0;
	double negative_points = 0.0;
	double counter = 0.0;
	int size = chromosome.size();

	typedef std::pair< double, unsigned > ValueKeyPair;
	std::vector< ValueKeyPair > rank(chromosome.size());
	
	
  
	for(int i = 0; i < size; i++){
		rank[i] = ValueKeyPair(chromosome[i], i);
		
		if(chromosome[i] > 0.5){	//Executa a busca apenas se for incluído na Click
			for(int j=i; j<size; j++){
				if(chromosome[j] > 0.5){
					if(mat[i][j] == 0){
						negative_points++;
					}
				}
			}
			counter++;
		}
	}



	// Here we sort 'permutation', which will then produce a permutation of [n]
	// stored in ValueKeyPair::second:
	std::sort(rank.begin(), rank.end());

	// permutation[i].second is in {0, ..., n - 1}; a permutation can be obtained as follows
	std::list< unsigned > permutation;
	for(std::vector< ValueKeyPair >::const_iterator i = rank.begin(); i != rank.end(); ++i) {
		permutation.push_back(i->second);
	}

	// Se não for clique
	if(negative_points > 0){
		myFitness = negative_points;
	}
	else{
		myFitness = 1/counter;
	}

	return myFitness;
}