/* 
* Copyright 2014-2016 Friedemann Zenke
*
* This file is part of Auryn, a simulation package for plastic
* spiking neural networks.
* 
* Auryn is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
* 
* Auryn is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with Auryn.  If not, see <http://www.gnu.org/licenses/>.
*
* If you are using Auryn or parts of it for your work please cite:
* Zenke, F. and Gerstner, W., 2014. Limits to high-speed simulations 
* of spiking neural networks using general-purpose computers. 
* Front Neuroinform 8, 76. doi: 10.3389/fninf.2014.00076
*/

#ifndef SPIKETIMINGSTIMGROUP_H_

#define SPIKETIMINGSTIMGROUP_H_

#include "auryn_definitions.h"
#include "System.h"
#include "StimulusGroup.h"

#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_01.hpp>
#include <boost/random/uniform_real.hpp>
#include <boost/random/uniform_int.hpp>
#include <boost/random/exponential_distribution.hpp>
#include <boost/random/normal_distribution.hpp>
#include <boost/random/variate_generator.hpp>

namespace auryn {


/*! \brief Struct to store single spike times */
struct spike_time_type {
	AurynTime t;
	NeuronID i;
};

typedef std::vector<spike_time_type> TemporalSpikePattern;


class RasStimGroup : public StimulusGroup
{
private:
	/*! \brief vector to store all spatio temporal patterns */
	std::vector<TemporalSpikePattern> patterns;

	void init();

protected:
	virtual void redraw();
	
public:
	/*! \brief Refractory period 
	 *
	 * Refractory period in seconds gets adde to the potentially stochastic off time and ensures a minimum interval between stimuli.
	 * */
	AurynDouble refractory_period;

	/*! \brief Default constructor */
	RasStimGroup(NeuronID n, string filename, string stimfile, StimulusGroupModeType stimulusmode=RANDOM, AurynFloat timeframe=0.0 );

	/*! \brief Constructor without stimfile. Patterns can be loaded afterwards using the load_patterns method. */
	RasStimGroup(NeuronID n, string stimfile, StimulusGroupModeType stimulusmode=RANDOM, AurynFloat timeframe=0.0 );

	/*! \brief Default destructor. */
	virtual ~RasStimGroup();

	/*! \brief Loads stimulus patterns from a designated file given */
	virtual void load_patterns( string filename );

	/*! Standard virtual evolve function */
	virtual void evolve();

};

}

#endif /*SPIKETIMINGSTIMGROUP_H_*/
