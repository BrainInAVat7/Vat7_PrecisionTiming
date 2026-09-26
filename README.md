# Vat7 Precision Timing

A thin wrapper over POSIX, Windows, and SDL3 precision timing functions.

---

## Summary

Vat7 is a collection of related programs I developed for learning
and personal use. As a personal project grew, it became clear that
parts of it should really be standalone utilities. On the off
chance that others might find them useful for learning or their own
learning or projects, I decided to share them.

The Vat7 Precision Timing utility is a very small API that offers
a thin wrapper around POSIX, Windows, and SDL3 precision timing
functions. It allows a program to be written such that it can
be compiled natively on Windows or POSIX systems. Alternatively,
it can be compiled to use SDL3.

SDL3 alone provides more or less the same abstraction; however,
the native versions of this more focused utility allows for a
focused precision timing API with less overhead.

Frankly, the SDL3 version is included because it is trivial to
write and because this utility was split off from a more general
SDL3 encapsulation layer. However, the SDL3 version of this utility
can be useful if the program is already using SDL3 elsewhere and
there is reason to allow it to be easily swapped out. Or it can serve
as a portability fallback for non-Windows, non-POSIX systems.

---


## Demo

The source code includes a small demo program that prints the frequency
value, then each second prints the number of seconds and current count
value. The demo illustrates the second usage pattern described above, and
it can be used to confirm the utility is working in the user's OS or
development environment.

---


## Dependencies
*This utility requires a 64bit environment or at least support of the
uint64_t type in C.*

The utility is compatible with windows and POSIX and has no
dependencies beyond the OS environment itself.

The SDL3 version requires SDL3 (obviously), and is compatible with
any SDL3 supported environment.

---


## Installation
Clone the repository using:
*git clone https://<no link>github.com/BrainInAVat7/Vat7_PrecisionTiming*

The source files and header are then available for inclusion and
compilation with local projects as the user sees fit.

**Running the demo**
A *Makefile* is included to generate the demo binary on POSIX systems.
Simply run: *Make* to compile the demo. It can be compiled and run
using: *Make run-demo*

The SDL version of the demo can be generated with: *Make sdl*
The SDL version demo can be compiled and run with: *Make sdl-demo*

*make clean* will delete all demo binaries.

For Windows users a *build.bat* file is included. It functions identically
to the POSIX *Makefile*. All the above-described commands can be used
with '*build.bat*' substituted for '*make*'.

---


## API

Header location: Vat7_PrecisionTiming/include

Header: vat7_precision_timing.h

vt7_pt_count()
>Takes no arguments and returns an unsigned 64bit integer count value:
>
>The count should not be interpreted in isolation and differs by platform;
>however, it is guaranteed to be monotonic. Intended usage is to subtract
>count values to obtain a difference. Used in conjunction with
>'vt7_pt_frequency()' the count difference can be used to calculate real
>elapsed time in seconds to a precision of fractions of a millisecond.

vt7_pt_frequency()
>Takes no arguments and returns an unsigned 64bit integer count per second:
>
>The result is intended to be used in conjunction with 'vt7_pt_count()' to
>calculate real elapsed time in seconds to a precision of fractions of a
>millisecond. The difference between count values can be divided by the
>frequency value, or frequency can be added to a count to calculate the
>count value at which a desired real time interval has elapsed.
>
>The frequency value is guaranteed to be the same for the lifetime of a
>process, so the value may be safely cached.

---


## Usage Patterns

There are two primary usage patterns, though others are certainly possible.

**Pattern 1**

```C
uint64_t freq = vt7_pt_frequency();
uint64_t initial_count = vt7_pt_count();

//do stuff

double seconds = (double)(vt7_pt_count() - initial_count) / (double)freq;
```


**Pattern 2**

```C
uint64_t freq = vt7_pt_frequency();
uint64_t seconds_to_run = 10;
uint64_t last_count = vt7_pt_count();
uint64_t next_tick_count = last_count + freq;
uint64_t seconds = 0;

while (seconds <= seconds_to_run)
{
    //do_stuff//

    now = vt7_pt_count();
    if now >= next_tick_count)
    {
        seconds++;
        // current count + count/second - (amount count overshot this tick)
        next_tick_count = now + freq - (now - next_tick_count);
    }
}
```

---


## Use of AI

*No code was generated using AI tools in this or any other Vat7 project*

ChatGPT was used to generate the build.bat. It was given a hand-written
makefile and prompted to generate a build.bat file that would exhibit
equivalent behavior. The file was then audited for correctness.

I have used AI as a resource for searching and explaining documentation,
identifying bugs/typos, and general information gathering. In short, I
have used it as a faster and more amiable *Stack Exchange*.
