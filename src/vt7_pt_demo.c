/* Author: BrainInAVat7
 * Date: 09/27/26
 * COPYRIGHT: (c) 2026 BrainInAVat7
 * LICENSE: AGPL-3.0
 *
 * A simple demo of the Vat7 Precision Timing Utility
 *
 * The program prints the precision timing frequency value,
 * then for 20 seconds will print the precision count value
 * and seconds elapsed each second. It then exits.
 *
 * See README.md for more information.
 */

#include "vat7_precision_timing.h"

#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


int main (void)
{
	uint64_t frequency = vt7_pt_frequency();
	puts("\n\nVat7 Precision Timing Demo\n");
	printf("Precision Timing Frequency: %"PRIu64"\n\n", frequency);

	int seconds = 0;
	uint64_t last_count = vt7_pt_count();
	uint64_t next_tick_count = last_count + frequency;
	printf("Seconds: %d\n", seconds);
	printf("Count: %"PRIu64"\n", last_count);

	while (seconds < 20)
	{
		uint64_t count = vt7_pt_count();
		if (count >= next_tick_count)
		{
			seconds++;
			printf("Seconds: %d\n", seconds);
			printf("Count: %"PRIu64"\n", count);
			// This is overly cautious. It recovers if a tick
			// gets skipped, but the program would have to
			// stall for over a second for that to happen.
			while(next_tick_count < count)
			{
				next_tick_count += frequency;
			}
		}
		last_count = count;
	}
	puts("\nVat7 Precision Timing Demo Complete\n");

	return EXIT_SUCCESS;
}
