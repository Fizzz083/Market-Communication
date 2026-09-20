# Market Communication — Feature Specification

## Roles

### Owner
- Register a company/organization.
- Register an owner account.
- Create a bank account during registration.
- Add initial products.
- Log in.
- View profile.
- View products.
- Add products.
- Update product information.
- Delete products.
- View organization workers.
- View organization conversations.
- Reply to organization conversations.
- View customer conversations.
- Reply to customer conversations.
- Log out.

### Worker
- Join an existing organization.
- Create a worker account.
- Create a bank account.
- Log in.
- View profile.
- View company products.
- Read organization conversations.
- Reply to organization conversations.
- Read customer conversations.
- Reply to customer conversations.
- Log out.

### User / Customer
- Create a user account.
- Create a bank account.
- Log in.
- View profile.
- Search organizations.
- Enter the organization/product interaction flow.
- Use local balance information in the purchase flow.
- Log out.

## Product Features

Each product has:

- Name
- Price
- Quantity

Operations:

```text
Create
  ↓
Store in goods.txt
  ↓
Read / Display
  ↓
Update
  ↓
Delete
```

## Banking Features

- Open account
- Store account number
- Store balance
- Display account
- Read balance
- Update balance
- Resolve organization owner

## Messaging Features

### Customer ↔ Organization

```text
Customer
   │
   ├── send ──> client_conversation/<organization>.txt
   │
   └── read <── same file
```

### Organization ↔ Organization

```text
Organization
   │
   ├── send ──> org_conversation/<organization>.txt
   │
   └── read <── same file
```

## Data Integrity / Validation Already Present

- Organization-name existence checking.
- Global username collision checking.
- Login username lookup.
- Password comparison.
- Worker organization existence checking.

## Not Implemented as a Production Feature

- Password hashing
- SQL/NoSQL database
- Network API
- Cloud storage
- Payment gateway
- Real banking integration
- Web UI
- Mobile UI
- Distributed messaging
- Automated tests
- Role-based security framework
- Session/token authentication
