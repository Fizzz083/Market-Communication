# Market Communication Documentation

This documentation pack was generated from the source currently present in:

**Fizzz083/Market-Communication**

Repository:
https://github.com/Fizzz083/Market-Communication

## Documents

- `PROJECT_OVERVIEW.md` — complete project documentation, architecture, feature inventory, technology stack, class model and modernization notes.
- `FEATURES.md` — feature-by-feature specification by user role.
- `TECHNOLOGY_ARCHITECTURE.md` — technologies, code architecture, dependency structure and persistence strategy.
- `FLOW_DIAGRAMS.md` — Mermaid diagrams for application, authentication, owner, worker, customer, product, banking, messaging and data flows.

## Quick Summary

The project is a C++ console application called **BUSYness PANDA**. It provides a small marketplace/communication model with:

- Owner accounts
- Worker accounts
- Customer/user accounts
- Organizations
- Products
- Product CRUD
- Worker membership
- Simulated bank accounts
- Organization search
- Customer ↔ organization communication
- Organization ↔ organization communication
- File-based persistence

## Current Technology

```text
C++
 ├── STL
 ├── fstream / stringstream
 ├── vector / map
 ├── OOP + inheritance
 └── Console I/O

Persistence
 └── Plain text files
```

## Main Flow

```text
Start
  ↓
Sign Up / Log In
  ↓
Owner / Worker / User
  ↓
Role-specific dashboard
  ↓
Organization / Product / Bank / Communication operations
  ↓
Local text-file persistence
```

## Important Note

The diagrams and documentation distinguish current implementation from recommended production architecture. The production architecture sections are recommendations, not features currently implemented in the repository.
