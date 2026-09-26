/* Author: BrainInAVat7
 * Date: 09/16/2026
 *
 * This timing helper provides a thin abstraction over
 * POSIX, Windows, and SDL3 functions to get a precision
 * timing count and precision timing frequency.
 *
 * This file implements the POSIX version.
 *
 * For more information see attached README.md
 * See LICENSE for licensing information.
 */

#define _POSIX_C_SOURCE 199309L

#include "vat7_precision_timing.h"

#include <stdint.h>
#include <time.h>

#include <unistd.h>


#define VAT7_NANOSECONDS_PER_SECOND (uint64_t)1000000000


/* Get a precision timing count at sub-microsecond resolution.
 * These timing counts are only meaningful when compared relatively
 * to one another.
 */
uint64_t vt7_pt_count (void)
{
	struct timespec ts;
	/* This returns 0 on success, -1 on failure */
	int failure = clock_gettime(CLOCK_MONOTONIC, &ts);

	if (!failure)
	{

		return (uint64_t)ts.tv_sec * VAT7_NANOSECONDS_PER_SECOND
			+ (uint64_t)ts.tv_nsec;
	}
	else
	{
		/* Real value can never realistically be 0 because
		 * that would represent the exact nanosecond the
		 * timer initialized, usually system start time */
		return 0;
	}
}


/* Get a precision timing frequency per second.
 * This is meant to be used with differences between precision
 * timer count values to calculate real time elapsed.
 *
 * (count_1 - count_2) / frequency = seconds elapsed
 */
uint64_t vt7_pt_frequency (void)
{
	/* This works because counter value is in nanoseconds */
	return VAT7_NANOSECONDS_PER_SECOND;
}


#undef VAT7_NANOSECONDS_PER_SECOND
#undef _POSIX_C_SOURCE
