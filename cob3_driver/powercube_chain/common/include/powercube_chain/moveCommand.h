/****************************************************************
 *
 * Copyright (c) 2010
 *
 * Fraunhofer Institute for Manufacturing Engineering	
 * and Automation (IPA)
 *
 * +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *
 * Project name: care-o-bot
 * ROS stack name: cob3_driver
 * ROS package name: powercube_chain
 * Description: These classes describe motion commands.
 *								
 * +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *			
 * Author: Felix Geibel, email:Felix.Geibel@gmx.de
 * Supervised by: Alexander Bubeck, email:alexander.bubeck@ipa.fhg.de
 *
 * Date of creation: Sept 2007
 * ToDo:
 *
 * +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Fraunhofer Institute for Manufacturing 
 *       Engineering and Automation (IPA) nor the names of its
 *       contributors may be used to endorse or promote products derived from
 *       this software without specific prior written permission.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License LGPL as 
 * published by the Free Software Foundation, either version 3 of the 
 * License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License LGPL for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public 
 * License LGPL along with this program. 
 * If not, see <http://www.gnu.org/licenses/>.
 *
 ****************************************************************/

#ifndef __MOVE_COMMAND_H__
#define __MOVE_COMMAND_H__


class RampCommand
{
	public:
		RampCommand(double x0, double v0, double xtarget, double amax, double vmax);
		RampCommand(const RampCommand& rc);
		
		virtual RampCommand& operator=(const RampCommand& rc);
			  
		virtual ~RampCommand() { if (m_nachumkehr) delete m_nachumkehr; }
		
		/// @brief returns the planned position for TimeElapsed (seconds)
		virtual double getPos(double TimeElapsed);
		
		/// @brief returns the planned velocity for TimeElapsed (seconds)
		virtual double getVel(double TimeElapsed);
		
		/// @brief returns the planned total time for the movement (in seconds)
		virtual double getTotalTime();
		
		static void calculateAV(double x0, double v0, double xtarget, double time, double T3, double amax, double vmax, double& a, double& v);
		
		double T1() const { return m_T1; }
		double T2() const { return m_T2; }
		double T3() const { return m_T3; }
		
	private:
		double m_x0, m_v0;
		double m_xtarget;
		double m_amax, m_vmax;
		
		double m_T1, m_T2, m_T3;
		double m_a1, m_v2, m_a3;
		bool m_umkehr;
		RampCommand * m_nachumkehr;
};
		
#endif
