# Market Communication — Flow & Visualization Pack

## 1. Master Flow

```mermaid
flowchart TD
    START([Application Start])
    START --> MENU[Main Menu]

    MENU --> SIGNUP[Sign Up]
    MENU --> LOGIN[Log In]
    MENU --> EXIT([Exit])

    SIGNUP --> ROLE1{Role}
    ROLE1 --> OS[Owner Sign Up]
    ROLE1 --> WS[Worker Sign Up]
    ROLE1 --> US[User Sign Up]

    OS --> OM[Owner Menu]
    WS --> WM[Worker Menu]
    US --> UM[User Menu]

    LOGIN --> ROLE2{Role}
    ROLE2 --> OL[Owner Login]
    ROLE2 --> WL[Worker Login]
    ROLE2 --> UL[User Login]

    OL --> OM
    WL --> WM
    UL --> UM

    OM --> OP[Products / Workers / Profile / Conversations]
    WM --> WP[Products / Profile / Conversations]
    UM --> UP[Profile / Search Organization]

    OP --> MENU
    WP --> MENU
    UP --> MENU
```

## 2. Owner Product Lifecycle

```mermaid
stateDiagram-v2
    [*] --> ProductCreation
    ProductCreation --> Stored
    Stored --> Viewed
    Viewed --> Updated
    Updated --> Stored
    Viewed --> Deleted
    Deleted --> [*]
```

## 3. Account Creation

```mermaid
sequenceDiagram
    participant R as Role
    participant A as Application
    participant U as all_user_list.txt
    participant D as Role Data File
    participant B as bank.txt

    R->>A: Enter username
    A->>U: Check username
    U-->>A: Available
    R->>A: Enter account details
    A->>D: Save role record
    A->>U: Register username
    A->>B: Create bank record
    A-->>R: Registration successful
```

## 4. Owner Registration

```mermaid
flowchart TD
    A[Company Name] --> B{Company Exists?}
    B -->|Yes| A
    B -->|No| C[Username]
    C --> D{Username Exists?}
    D -->|Yes| C
    D -->|No| E[Password + Name + Phone]
    E --> F[Create Owner]
    F --> G[Register Username]
    G --> H[Create Organization]
    H --> I[Create Worker Mapping Entry]
    I --> J[Create Bank Account]
    J --> K[Add Initial Products]
    K --> L[Registration Complete]
```

## 5. Worker Registration

```mermaid
flowchart TD
    A[Company Name] --> B{Company Exists?}
    B -->|No| A
    B -->|Yes| C[Username]
    C --> D{Username Exists?}
    D -->|Yes| C
    D -->|No| E[Password + Name + Phone]
    E --> F[Create Worker]
    F --> G[Register Username]
    G --> H[Create Bank Account]
    H --> I[Worker Ready]
```

## 6. User Registration

```mermaid
flowchart TD
    A[Username] --> B{Username Exists?}
    B -->|Yes| A
    B -->|No| C[Password + Name + Phone]
    C --> D[Create User]
    D --> E[Register Username]
    E --> F[Create Bank Account]
    F --> G[User Ready]
```

## 7. Organization Relationship

```mermaid
flowchart LR
    O[Owner] --> ORG[Organization]
    ORG --> W1[Worker]
    ORG --> W2[Worker]
    ORG --> W3[Worker]
    ORG --> P1[Product]
    ORG --> P2[Product]
    U[Customer] --> ORG
```

## 8. Communication Topology

```mermaid
flowchart LR
    U[Customer] <--> C1[Client Conversation File]
    C1 <--> O[Organization / Owner]

    O <--> C2[Organization Conversation File]
    C2 <--> O2[Another Organization / Worker]
```

## 9. Data Storage Map

```mermaid
flowchart TB
    APP[C++ Application]

    APP --> A[Authentication]
    APP --> B[Organizations]
    APP --> C[Products]
    APP --> D[Banking]
    APP --> E[Messaging]

    A --> A1[all_user_list.txt]
    A --> A2[owner.txt]
    A --> A3[worker.txt]
    A --> A4[user.txt]

    B --> B1[organization.txt]
    B --> B2[organizations_worker.txt]

    C --> C1[goods.txt]

    D --> D1[bank.txt]

    E --> E1[client_conversation/]
    E --> E2[org_conversation/]
```

## 10. Purchase-Oriented Flow

```mermaid
sequenceDiagram
    participant U as User
    participant B as Bank Module
    participant O as Organization Search
    participant G as Goods Module
    participant S as Storage

    U->>B: Get balance + account
    B->>S: Read bank.txt
    S-->>B: Account data
    B-->>O: Balance + account
    U->>O: Search/select organization
    O->>G: Get product price/quantity
    G->>S: Read goods.txt
    S-->>G: Product data
    G-->>O: Product information
    O->>B: Update balance
    O->>G: Update stock
    B->>S: Rewrite bank.txt
    G->>S: Rewrite goods.txt
```

## 11. Return-to-Menu Pattern

```mermaid
flowchart TD
    A[Dashboard] --> B[Execute Action]
    B --> C[Display Result]
    C --> D{More Action?}
    D -->|Yes| A
    D -->|No / Logout| E[Main Menu]
    E --> F{Exit?}
    F -->|No| A
    F -->|Yes| G([Terminate])
```

## 12. Conceptual Modern Architecture

```mermaid
flowchart TB
    CLIENT[Client UI]
    API[Backend API]

    CLIENT --> API

    API --> AUTH[Auth]
    API --> USER[User]
    API --> ORG[Organization]
    API --> PRODUCT[Product]
    API --> ORDER[Order]
    API --> PAYMENT[Wallet/Payment]
    API --> MESSAGE[Messaging]

    AUTH --> DB[(Database)]
    USER --> DB
    ORG --> DB
    PRODUCT --> DB
    ORDER --> DB
    PAYMENT --> DB

    MESSAGE --> MQ[(Message Broker)]
    API --> CACHE[(Cache)]
```
