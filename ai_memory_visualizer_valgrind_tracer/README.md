# AI Memory Visualizer & Valgrind Tracer

## Overview
This project focuses on building an accurate mental model of C memory management, analyzing stack vs. heap dynamics, evaluating AI-generated explanations, and tracking memory issues using Valgrind.

## Directory Structure
- `analysis/memory_maps.md`: Comprehensive memory mapping and corrections for execution stack, heap, and aliasing scenarios.
# AI Memory Visualizer, Valgrind Tracer & Crash Analysis

## Executive Overview
This project establishes a concrete, rule-based mental model of C memory architecture. It focuses on distinguishing **Stack** vs **Heap** lifetimes, tracing **Pointer Aliasing**, interpreting **Valgrind memory leaks/violations**, diagnosing deterministic **Segmentation Faults**, and critically evaluating **AI-generated hypotheses**.

---

## Repository Structure

```text
ai_memory_visualizer_valgrind_tracer/
├── README.md                  # Project overview and peer-review verification matrix
└── analysis/
    ├── memory_maps.md         # Task 0: Stack vs Heap lifetimes & pointer aliasing analysis
    ├── valgrind_analysis.md   # Task 1: Valgrind memory leak & invalid read/write classification
    └── crash_report.md        # Task 2: Deterministic crash analysis & NULL pointer dereference
