/* Author: BrainInAVat7
 * Date: 10/01/26
 * COPYRIGHT: (c) 2026 BrainInAVat7
 * LICENSE: AGPL-3.0
 *
 * A simple demo of the Vat7 Precision Timing Utility
 *
 * The program
 *
 * See README.md for more information.
 */

#include "vat7_precision_timing.h"

#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


#define VAT7_PT_DEMO_SECONDS_TO_RUN 20


int main (void)
{
	uint64_t frequency = vt7_pt_frequency();
	puts("\n\nVat7 Precision Timing Demo 2\n");

	puts("Calculating the sum of numbers from 1 to 300,000,000:");
	long long int number = 300000000;
	long long int sum = 1;

	uint64_t start_count = vt7_pt_count();
	while (number > 0)
	{
		sum += number;
		number--;
	}
	uint64_t end_count = vt7_pt_count();
	double seconds = (double)(end_count - start_count)
			/ (double)frequency;
	printf("Value: %lld calculated in %f seconds", sum, seconds);

	puts("\nVat7 Precision Timing Demo 2 Complete\n");
	puts("press ENTER to end");
	getchar();

	return EXIT_SUCCESS;
}
