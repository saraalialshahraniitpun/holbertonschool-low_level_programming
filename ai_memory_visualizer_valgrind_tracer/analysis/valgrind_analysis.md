# Valgrind & Memory Tracer Analysis

## Overview
This document provides a detailed breakdown of runtime memory issues detected by Valgrind when executing C programs (`heap_example.c` and `aliasing_example.c`). It connects raw Valgrind diagnostics to concrete memory lifetime violations, ownership loss, and classifies each memory flaw accurately.

---

## 1. Analysis: Heap Memory & Memory Leaks (`heap_example.c`)

### Valgrind Diagnostic Output & Classification

* **Error Category:** Memory Leak (Definitely Lost / Definitely Leaked)
* **Valgrind Message Example:**
  ```text
  ==12345== 40 bytes in 1 blocks are definitely lost in loss record 1 of 1
  ==12345==    at 0x483B7F3: malloc (vg_replace_malloc.c:380)
  ==12345==    by 0x10915E: create_buffer (heap_example.c:12)
  ==12345==    by 0x10918F: main (heap_example.c:22)
