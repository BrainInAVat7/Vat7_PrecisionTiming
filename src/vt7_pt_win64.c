/* Author: BrainInAVat7
 * Date: 09/16/2026
 *
 * This timing helper provides a thin abstraction over
 * POSIX, Windows, and SDL3 functions to get a precision
 * timing count and precision timing frequency.
 *
 * This file implements the Windows version.
 *
 * For more information see attached README.md
 * See LICENSE for licensing information.
 */


#include "vat7_precision_timing.h"

#include <stdbool.h>
#include <stdint.h>
#include <time.h>

#include <windows.h>


/* Get a precision timing count at sub-microsecond resolution.
 * These timing counts are only meaningful when compared relatively
 * to one another.
 */
uint64_t vt7_pt_count (void)
{
	/* LARGE_INTEGER is a struct so windows can support
	 * 32 bit systems */
	LARGE_INTEGER windows_count;
	/* On Windows xp and later, QueryPeformanceCounter
	 * is guaranteed to never return a value indicating failure */
	QueryPerformanceCounter(&windows_count);
	/* QuadPart holds value if system supports 64 bit ints
	 * This program does not aim to support non-64 bit systems. */
	return (uint64_t)windows_count.QuadPart;
}


/* Get a precision timing frequency per second.
 * This is meant to be used with differences between precision
 * timer count values to calculate real time elapsed.
 *
 * (count_1 - count_2) / frequency = seconds elapsed
 */
uint64_t vt7_pt_frequency (void)
{
	static uint64_t frequency = 0;
	if (!frequency)
	{
		/* LARGE_INTEGER is a struct so windows can support
		 * 32 bit systems */
		LARGE_INTEGER windows_frequency;
		/* On Windows xp and later, QueryPeformanceFrequency
		 * is guaranteed to never return a value indicating failure */
		QueryPerformanceFrequency(&windows_frequency);
		/* QuadPart holds value if system supports 64 bit ints
		 * This program does not aim to support non-64 bit systems. */
		frequency = (uint64_t)windows_frequency.QuadPart;
	}
	return frequency;
}
