/*
 * =======================================================================================
 *
 *      Filename:  power_types.h
 *
 *      Description:  Types file for power module.
 *
 *      Version:   <VERSION>
 *      Released:  <DATE>
 *
 *      Author:  Jan Treibig (jt), jan.treibig@gmail.com
 *      Project:  likwid
 *
 *      Copyright (C) 2013 Jan Treibig 
 *
 *      This program is free software: you can redistribute it and/or modify it under
 *      the terms of the GNU General Public License as published by the Free Software
 *      Foundation, either version 3 of the License, or (at your option) any later
 *      version.
 *
 *      This program is distributed in the hope that it will be useful, but WITHOUT ANY
 *      WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
 *      PARTICULAR PURPOSE.  See the GNU General Public License for more details.
 *
 *      You should have received a copy of the GNU General Public License along with
 *      this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * =======================================================================================
 */

#ifndef POWER_TYPES_H
#define POWER_TYPES_H

#include <stdint.h>

/** \addtogroup PowerMon Power and Energy monitoring module
 *  @{
 */
/*! \brief Enum of possible power measurement types
*/
typedef enum {
    PKG = 0, /*!< \brief PKG domain, mostly one CPU socket/package */
    PP0 = 1, /*!< \brief PP0 domain, not clearly defined by Intel */
    PP1 = 2, /*!< \brief PP1 domain, not clearly defined by Intel */
    DRAM = 3 /*!< \brief DRAM domain, the memory modules */
} PowerType;

/*! \brief Information structure of CPU's turbo mode
\extends PowerInfo
*/
typedef struct {
    int numSteps; /*!< \brief Amount of turbo mode steps/frequencies */
    double* steps; /*!< \brief List of turbo mode steps */
} TurboBoost;

/*! \brief Information structure of CPU's power measurement facility
*/
typedef struct {
    double baseFrequency; /*!< \brief Base frequency of the CPU */
    double minFrequency; /*!< \brief Minimal frequency of the CPU */
    TurboBoost turbo; /*!< \brief Turbo boost information */
    double powerUnit; /*!< \brief Multiplier for power measurements */
    double energyUnit; /*!< \brief Multiplier for energy measurements */
    double timeUnit; /*!< \brief Multiplier for time information */
    double tdp; /*!< \brief Thermal Design Power (maximum amount of heat generated by the CPU) */
    double minPower; /*!< \brief Minimal power consumption of the CPU */
    double maxPower; /*!< \brief Maximal power consumption of the CPU */
    double maxTimeWindow; /*!< \brief Minimal power measurement interval */
    uint32_t supportedTypes;
} PowerInfo;

/*! \brief Power measurement data for start/stop measurements
*/
typedef struct {
    uint32_t before; /*!< \brief Counter state at start */
    uint32_t after; /*!< \brief Counter state at stop */
} PowerData;

/** \brief Pointer for exporting the PowerInfo data structure */
typedef PowerInfo* PowerInfo_t;
/** \brief Pointer for exporting the PowerData data structure */
typedef PowerData* PowerData_t;
/** @}*/

extern PowerInfo power_info;
extern const uint32_t power_regs[4];


#endif /*POWER_TYPES_H*/
