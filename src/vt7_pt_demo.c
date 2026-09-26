/* A simple manual test of the Vat7 timing abstraction
 *
 * Author: BrainInAVat7
 * Date: 09/27/26
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
	puts("\n\nVat7 Timing Abstraction Demo\n");
	printf("Precision Timing Frequency: %"PRIu64"\n\n", frequency);

	int seconds = 0;
	uint64_t last_count = vt7_pt_count();
	uint64_t next_tick_count = last_count + frequency;
	uint64_t accumulated_count = last_count;
	printf("Seconds: %d\n", seconds);
	printf("Count: %"PRIu64"\n", last_count);

	while (seconds < 20)
	{
		uint64_t count = vt7_pt_count();
		accumulated_count += count - last_count;
		if (accumulated_count >= next_tick_count)
		{
			seconds++;
			next_tick_count += frequency;
			printf("Seconds: %d\n", seconds);
			printf("Count: %"PRIu64"\n", count);
		}
		last_count = count;
	}
	puts("\nDemo Complete\n");

	return EXIT_SUCCESS;
}
