/* Author: BrainInAVat7
 * Date: 09/19/2026
 *
 * This timing helper provides a thin abstraction over
 * POSIX, Windows, and SDL3 functions to get a precision
 * timing count and precision timing frequency.
 *
 * This file implements the SDL3 version.
 *
 * For more information see attached README.md
 * See LICENSE for licensing information.
 */


#include "vat7_precision_timing.h"

#include <stdint.h>

#include <SDL3/SDL.h>


/* Get a precision timing count at sub-microsecond resolution.
 * These timing counts are only meaningful when compared relatively
 * to one another.
 */
uint64_t vt7_pt_count (void)
{
	return SDL_GetPerformanceCounter();
}


/* Get a precision timing frequency per second.
 * This is meant to be used with differences between precision
 * timer count values to calculate real time elapsed.
 *
 * (count_1 - count_2) / frequency = seconds elapsed
 */
uint64_t vt7_pt_frequency (void)
{
	return SDL_GetPerformanceFrequency();
}
