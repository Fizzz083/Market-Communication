# Market Communication — Project Documentation

> Repository: https://github.com/Fizzz083/Market-Communication  
> Current repository state reviewed: `master`, public repository, 2 commits.

## 1. Project Overview

**Market Communication** is a C++ console-based marketplace/communication application branded in the source code as **BUSYness PANDA**.

The application models three kinds of users:

- **Owner** — owns an organization, manages products and workers, maintains a bank account, and communicates with customers or other organizations.
- **Worker** — belongs to an organization, can view company products, maintain a bank account/profile, and communicate with the organization or customers.
- **User/Customer** — maintains a profile and bank account, searches organizations, views/selects products through the organization search/purchase flow, and communicates with organizations.

The implementation is a small educational/project-style C++ application using local text files as its persistence layer.

## 2. Core Capabilities

### Authentication and account creation

The main menu provides:

1. Sign Up
2. Log In
3. Exit

Sign-up is split into:

- Owner sign-up
- Worker sign-up
- User sign-up

Each account records a username, password, name, and phone number. Owner and worker accounts also associate the account with an organization.

The code checks the global username list before creating a new account.

### Owner capabilities

After owner login, the menu provides:

- My Profile
- My Products
- My Workers
- Add Product
- Edit Product Information
  - Update Product
  - Delete Product
- Organization Conversation
- Open Conversation
- Log Out

Owner registration also creates/initializes organization-related records, a bank account, and initial products.

### Worker capabilities

After worker login:

- My Profile
- My Company's Products
- Organization Conversation
- Open Conversation
- Log Out

Workers are linked to an existing organization during registration.

### Customer/User capabilities

After user login:

- My Profile
- Search Organization
- Log Out

The organization-search path obtains the customer's bank balance/account information and passes it to the organization search/purchase workflow.

### Product management

Products contain:

- Product name
- Price
- Quantity

Owners can:

- Add multiple products
- Display organization products
- Update a product's price and quantity
- Delete a product

Product records are stored in `goods.txt`.

### Bank/account simulation

The application contains a simple bank-account abstraction.

Supported operations include:

- Open bank account
- Store bank account number
- Store account balance
- Display account information
- Retrieve balance for a user
- Update a balance
- Resolve an organization owner's account

This is a local simulation rather than an integration with a real banking system.

### Organization management

Organizations contain:

- Organization name
- Owner
- Associated workers
- Products

The application checks organization names for uniqueness/existence and maintains organization-to-worker relationships.

### Communication

There are two communication directions:

1. **Customer ↔ Organization**
2. **Organization ↔ Organization**

Messages are persisted in local files under conversation directories.

The conversation module supports:

- Sending a message
- Reading previous messages
- Replying from the relevant user role

## 3. Main Technologies

| Area | Technology / Approach |
|---|---|
| Language | C++ |
| Application type | Console / terminal application |
| Standard library | C++ STL |
| Headers | `bits/stdc++.h` plus project headers |
| Persistence | Plain-text files |
| Data parsing | `fstream`, `stringstream`, vectors/maps |
| Main architecture | Procedural menu + object-oriented classes |
| Build/project artifacts | Code::Blocks project files are present |
| Networking | None identified |
| External database | None |
| External API | None |
| GUI | None |
| Authentication service | None; local file comparison |
| Messaging transport | None; local file storage |

The repository itself describes the application as a **“c++ console application.”**

## 4. High-Level Architecture

```mermaid
flowchart TD
    A[main.cpp<br/>Console Entry Point] --> B{Authentication}
    B --> C[Owner]
    B --> D[Worker]
    B --> E[User]

    C --> F[Owner Profile]
    C --> G[Organization / Products]
    C --> H[Workers]
    C --> I[Bank]
    C --> J[Conversations]

    D --> K[Worker Profile]
    D --> G
    D --> I
    D --> J

    E --> L[User Profile]
    E --> M[Search Organization]
    E --> I
    E --> J

    G --> N[(goods.txt)]
    H --> O[(organizations_worker.txt)]
    C --> P[(owner.txt)]
    D --> Q[(worker.txt)]
    E --> R[(user.txt)]
    I --> S[(bank.txt)]
    B --> T[(all_user_list.txt)]
    G --> U[(organization.txt)]
    J --> V[(conversation files)]
```

## 5. Repository Structure

```text
Market-Communication/
├── main.cpp
├── Bank.H
├── Owner.H
├── worker.h
├── user.h
├── organization.h
├── conversation.h
│
├── all_user_list.txt
├── bank.txt
├── goods.txt
├── organization.txt
├── organizations_worker.txt
├── owner.txt
├── user.txt
├── worker.txt
│
├── conversation/
├── client_conversation/
├── org_conversation/
│
├── Project_my.cbp
├── Project_my.depend
├── Project_my.layout
├── Proect_my.layout
│
├── bin/Debug/
└── obj/Debug/
```

## 6. Important Design Characteristics

### File-based persistence

Instead of a relational or document database, the program reads and rewrites `.txt` files.

Typical records are written with a simple `new` marker followed by space-separated values.

Example conceptual record:

```text
new username password full_name phone
```

Product records follow a compact organization/product representation:

```text
new organization product price quantity product price quantity ...
```

### Object-oriented model

Important classes include:

- `bank`
- `goods`
- `organization`
- `conversation`
- `owner`
- `worker`
- `user`

There is also inheritance between several of these components.

For example, the owner class inherits from:

```text
bank
organization
conversation
```

This gives the owner access to financial, product/organization, and communication behavior.

## 7. User Journey

```mermaid
flowchart TD
    Start([Start Application]) --> Welcome[BUSYness PANDA]
    Welcome --> Auth{Sign Up or Log In}

    Auth --> Signup[Sign Up]
    Signup --> Role{Choose Role}
    Role --> OwnerSignup[Owner]
    Role --> WorkerSignup[Worker]
    Role --> UserSignup[User]

    OwnerSignup --> OwnerData[Create Owner + Organization + Bank + Products]
    WorkerSignup --> WorkerData[Create Worker + Organization Link + Bank]
    UserSignup --> UserData[Create User + Bank]

    OwnerData --> Main[Main Menu]
    WorkerData --> Main
    UserData --> Main

    Auth --> Login[Log In]
    Login --> RoleLogin{Choose Role}
    RoleLogin --> OwnerLogin[Owner Login]
    RoleLogin --> WorkerLogin[Worker Login]
    RoleLogin --> UserLogin[User Login]

    OwnerLogin --> OwnerMenu[Owner Menu]
    WorkerLogin --> WorkerMenu[Worker Menu]
    UserLogin --> UserMenu[User Menu]

    OwnerMenu --> Logout[Log Out]
    WorkerMenu --> Logout
    UserMenu --> Logout
    Logout --> Welcome
```

## 8. Owner Flow

```mermaid
flowchart TD
    A[Owner Login] --> B[Owner Menu]

    B --> C[My Profile]
    B --> D[My Products]
    B --> E[My Workers]
    B --> F[Add Product]
    B --> G[Edit Product Info]
    B --> H[Organization Conversation]
    B --> I[Open Conversation]
    B --> J[Log Out]

    F --> K[Enter Product Name]
    K --> L[Enter Price]
    L --> M[Enter Quantity]
    M --> N[Write goods.txt]

    G --> O{Update or Delete}
    O --> P[Update Product]
    O --> Q[Delete Product]
    P --> N
    Q --> N

    H --> R[Read Organization Messages]
    R --> S[Optional Reply]

    I --> T[Read Customer Messages]
    T --> U[Optional Reply]
```

## 9. Worker Flow

```mermaid
flowchart TD
    A[Worker Login] --> B[Worker Menu]

    B --> C[My Profile]
    B --> D[My Company's Products]
    B --> E[Organization Conversation]
    B --> F[Open Conversation]
    B --> G[Log Out]

    C --> H[Worker Details + Bank]
    D --> I[Read goods.txt]
    E --> J[Read Organization Conversation]
    J --> K[Reply]
    F --> L[Read Customer Conversation]
    L --> M[Reply]
```

## 10. Customer Flow

```mermaid
flowchart TD
    A[User Login] --> B[User Menu]
    B --> C[My Profile]
    B --> D[Search Organization]
    B --> E[Log Out]

    C --> F[Display User Profile]

    D --> G[Read Bank Balance]
    G --> H[Search Organization]
    H --> I[Organization/Product Selection]
    I --> J[Price + Quantity Processing]
    J --> K[Bank Balance Update]
    K --> L[Continue / Return]
```

## 11. Communication Flow

```mermaid
sequenceDiagram
    participant U as Customer/User
    participant C as Conversation Module
    participant F as Local Conversation File
    participant O as Organization/Owner/Worker

    U->>C: Send message
    C->>F: Append message
    O->>C: Open conversation
    C->>F: Read previous messages
    F-->>C: Messages
    C-->>O: Display sender + message
    O->>C: Reply
    C->>F: Append reply
```

## 12. Data Flow

```mermaid
flowchart LR
    UserInput[Console Input]

    UserInput --> AuthFiles[User / Owner / Worker Files]
    UserInput --> OrgFiles[Organization Files]
    UserInput --> ProductFiles[goods.txt]
    UserInput --> BankFiles[bank.txt]
    UserInput --> MessageFiles[Conversation Files]

    AuthFiles --> Runtime[Runtime Objects]
    OrgFiles --> Runtime
    ProductFiles --> Runtime
    BankFiles --> Runtime
    MessageFiles --> Runtime

    Runtime --> ConsoleOutput[Console Output]
```

## 13. Persistence Map

| File / Directory | Purpose |
|---|---|
| `all_user_list.txt` | Global username registry |
| `owner.txt` | Owner credentials/profile/organization data |
| `worker.txt` | Worker credentials/profile/organization data |
| `user.txt` | Customer/user credentials/profile data |
| `organization.txt` | Organization-owner mapping |
| `organizations_worker.txt` | Organization-worker relationships |
| `goods.txt` | Organization products, prices and quantities |
| `bank.txt` | Simulated bank accounts and balances |
| `conversation/` | Base conversation directory |
| `client_conversation/` | Customer ↔ organization messages |
| `org_conversation/` | Organization ↔ organization messages |

## 14. Class Relationship

```mermaid
classDiagram
    class bank {
        +string b_user_name
        +string bank_ac_no
        +int amount
        +open_bank_ac()
        +show_bank()
        +get_money()
    }

    class goods {
        +string pro_name
        +int price
        +int quantity
    }

    class organization {
        +string org_name
        +check_org()
        +add_good()
        +show_goods()
        +get_price()
        +edit_goods()
        +delete_goods()
        +show_all_org()
        +goods_update()
    }

    class conversation {
        +user_to_org_conversation()
        +org_to_org_conversation()
        +view_msg()
    }

    class owner {
        +user_name
        +organi
        +password
        +full_name
        +phone
    }

    class worker {
        +worker_user_name
        +worker_org
        +worker_pass
        +worker_full_name
        +worker_phone
    }

    class user {
        +user_name
        +password
        +full_name
        +phone
    }

    organization --|> goods
    owner --|> bank
    owner --|> organization
    owner --|> conversation
    worker --|> bank
    worker --|> organization
    worker --|> conversation
    user --|> bank
```

## 15. Feature Matrix

| Feature | Owner | Worker | User |
|---|:---:|:---:|:---:|
| Sign up | ✓ | ✓ | ✓ |
| Log in | ✓ | ✓ | ✓ |
| Profile | ✓ | ✓ | ✓ |
| Bank account | ✓ | ✓ | ✓ |
| View organization products | ✓ | ✓ | Via organization search |
| Add products | ✓ | — | — |
| Update products | ✓ | — | — |
| Delete products | ✓ | — | — |
| View workers | ✓ | — | — |
| Customer communication | ✓ | ✓ | ✓ |
| Organization communication | ✓ | ✓ | — |
| Search organizations | — | — | ✓ |
| Log out | ✓ | ✓ | ✓ |

## 16. Authentication Flow

```mermaid
flowchart TD
    A[Enter Username] --> B[Check all_user_list.txt]
    B --> C{Username exists?}

    C -->|No during signup| D[Collect Account Data]
    D --> E[Write Role-specific File]
    E --> F[Add Username to Global List]
    F --> G[Create Bank Account]

    C -->|Yes during login| H[Read Role-specific Record]
    H --> I[Compare Password]
    I --> J{Valid?}
    J -->|Yes| K[Create Logged-in Runtime Context]
    J -->|No| L[Login Failure]
```

## 17. Product Transaction Concept

The customer path obtains the customer's balance and bank account before invoking organization search. The organization module exposes price/quantity lookup and product-update functions, indicating that the project contains a purchase/stock-update workflow rather than being only a static product directory.

Conceptual flow:

```mermaid
flowchart TD
    A[Customer] --> B[Get Bank Balance]
    B --> C[Search Organization]
    C --> D[Select Product]
    D --> E[Get Product Price]
    E --> F[Check Quantity / Funds]
    F --> G[Update Product Quantity]
    G --> H[Update Customer Bank Balance]
    H --> I[Complete Purchase]
```

## 18. Control Flow Style

The program uses explicit menu loops and `goto` labels to return to menus.

Conceptually:

```text
Main Menu
   |
   +-- Sign Up --> Role Menu --> Registration --> Main Menu
   |
   +-- Log In --> Role Menu --> Role Dashboard --> Action --> Dashboard
   |
   +-- Exit
```

This makes the application easy to follow as a small console project, but it is not structured as a modern layered application.

## 19. Current Architecture Assessment

### Strengths

- Clear separation of major domain concepts.
- Three explicit user roles.
- Basic object-oriented modeling.
- Persistent data survives program restarts.
- Product, organization, banking and messaging concepts are connected.
- The project demonstrates inheritance, templates, STL containers, file I/O and menu-driven application design.

### Limitations / technical debt

These are observations from the current implementation, not missing requirements:

- Plain-text files are used instead of a database.
- Passwords are stored in readable text files.
- No password hashing is present.
- No authorization/session framework exists.
- File parsing is based heavily on whitespace-delimited tokens.
- Product names, names and messages cannot safely use arbitrary spaces in several data paths.
- There is no concurrent access strategy or transaction system.
- Bank behavior is only a local simulation.
- There is no network layer or real-time messaging transport.
- Error handling around file access is limited.
- The main control flow relies heavily on `goto`.
- Business logic and UI/input handling are tightly coupled.
- Several implementation details depend on relative filesystem paths and Windows-style backslashes.
- No automated test suite was identified in the repository.
- No external dependency/package management layer is evident.

## 20. Recommended Modernization Architecture

If this project were rebuilt as a production application, a more maintainable architecture would be:

```mermaid
flowchart TD
    UI[Web / Desktop / Mobile UI]
    API[Application API]
    AUTH[Authentication Service]
    ORG[Organization Service]
    PRODUCT[Product Service]
    ORDER[Order / Transaction Service]
    MSG[Messaging Service]
    BANK[Wallet / Payment Service]
    DB[(Relational Database)]
    MQ[(Message Broker)]
    CACHE[(Redis Cache)]

    UI --> API
    API --> AUTH
    API --> ORG
    API --> PRODUCT
    API --> ORDER
    API --> MSG
    API --> BANK

    AUTH --> DB
    ORG --> DB
    PRODUCT --> DB
    ORDER --> DB
    BANK --> DB

    MSG --> MQ
    API --> CACHE
```

A production redesign should also introduce:

- hashed passwords
- role-based access control
- database transactions
- structured domain models
- REST/GraphQL APIs
- validation
- centralized error handling
- automated tests
- logging
- audit trails
- secure secrets management
- proper order/payment state management

## 21. Suggested Modern Data Model

```mermaid
erDiagram
    USER {
        uuid id PK
        string username
        string password_hash
        string full_name
        string phone
        string role
    }

    ORGANIZATION {
        uuid id PK
        string name
        uuid owner_id FK
    }

    ORGANIZATION_MEMBER {
        uuid id PK
        uuid organization_id FK
        uuid user_id FK
        string role
    }

    PRODUCT {
        uuid id PK
        uuid organization_id FK
        string name
        decimal price
        int quantity
    }

    BANK_ACCOUNT {
        uuid id PK
        uuid user_id FK
        string account_number
        decimal balance
    }

    ORDER {
        uuid id PK
        uuid buyer_id FK
        uuid organization_id FK
        decimal total
        string status
    }

    ORDER_ITEM {
        uuid id PK
        uuid order_id FK
        uuid product_id FK
        int quantity
        decimal unit_price
    }

    MESSAGE {
        uuid id PK
        uuid sender_id FK
        uuid receiver_id FK
        uuid organization_id FK
        text body
        datetime created_at
    }

    USER ||--o{ ORGANIZATION : owns
    ORGANIZATION ||--o{ ORGANIZATION_MEMBER : has
    USER ||--o{ ORGANIZATION_MEMBER : belongs_to
    ORGANIZATION ||--o{ PRODUCT : sells
    USER ||--o| BANK_ACCOUNT : owns
    USER ||--o{ ORDER : places
    ORGANIZATION ||--o{ ORDER : receives
    ORDER ||--|{ ORDER_ITEM : contains
    PRODUCT ||--o{ ORDER_ITEM : included_in
    USER ||--o{ MESSAGE : sends
    USER ||--o{ MESSAGE : receives
```

## 22. End-to-End System View

```mermaid
flowchart TB
    subgraph Users
        OWNER[Owner]
        WORKER[Worker]
        CUSTOMER[Customer]
    end

    subgraph Application
        AUTH[Authentication]
        PROFILE[Profiles]
        ORG[Organization Management]
        PRODUCTS[Product Management]
        MARKET[Organization Search / Purchase]
        BANK[Bank Simulation]
        CHAT[Conversation]
    end

    subgraph Storage
        USERS[(user.txt)]
        OWNERS[(owner.txt)]
        WORKERS[(worker.txt)]
        ORGS[(organization.txt)]
        MEMBERS[(organizations_worker.txt)]
        GOODS[(goods.txt)]
        BANKDB[(bank.txt)]
        CLIENTCHAT[(client_conversation)]
        ORGCHAT[(org_conversation)]
    end

    OWNER --> AUTH
    WORKER --> AUTH
    CUSTOMER --> AUTH

    AUTH --> PROFILE
    OWNER --> ORG
    OWNER --> PRODUCTS
    WORKER --> ORG
    WORKER --> PRODUCTS
    CUSTOMER --> MARKET

    OWNER --> BANK
    WORKER --> BANK
    CUSTOMER --> BANK

    OWNER --> CHAT
    WORKER --> CHAT
    CUSTOMER --> CHAT

    AUTH --> USERS
    AUTH --> OWNERS
    AUTH --> WORKERS
    ORG --> ORGS
    ORG --> MEMBERS
    PRODUCTS --> GOODS
    BANK --> BANKDB
    CHAT --> CLIENTCHAT
    CHAT --> ORGCHAT
    MARKET --> GOODS
    MARKET --> BANKDB
```

## 23. File-by-File Responsibility

### `main.cpp`
Application entry point, top-level menus, sign-up/login routing, and role-specific dashboard routing.

### `Bank.H`
Local bank-account abstraction and balance lookup/update logic.

### `Owner.H`
Owner data model, owner registration/login helpers, organization initialization, and owner-specific operations.

### `worker.h`
Worker data model, worker registration/login, organization membership and worker listing/profile behavior.

### `user.h`
Customer/user registration, login, profile and customer-side entry points.

### `organization.h`
Organization and product domain logic, including product creation, display, price lookup, update/delete and stock-related functions.

### `conversation.h`
Message storage/retrieval for customer-to-organization and organization-to-organization communication.

### Text files
Persistent storage for users, organizations, products, bank records and messages.

## 24. Documentation Status

This documentation describes the implementation that is actually present in the reviewed repository. It intentionally separates:

- **Implemented features** — visible in the source.
- **Architecture interpretation** — derived from how source modules interact.
- **Modernization recommendations** — proposed improvements, not current functionality.

## 25. Source

Primary source reviewed:

https://github.com/Fizzz083/Market-Communication
