# Task Tracker CLI
<center font-size="32px">C++ CLI app to track your tasks and manage your to-do list</center>

> This repo is my version of the project "Task Tracker CLI" by [roadmap.sh](https://roadmap.sh/projects/task-tracker)
## 📖 Guide to use the CLI

### List of commands

| Command | Description | Example
| --- | --- | --- |
| `add [TITLE]`  | Create a new task | `task-cli add "TOTO"`
| `delete [ID]`  | Delete a task | `task-cli delete 1`
| `update [ID] [NEW_TITLE]`  | Update a task | `task-cli update 1 "TATA"`
| `mark-in-progress [ID]`  | Marking a task as in progress | `task-cli mark-in-progress 1`
| `mark-done [ID]`  | Marking a task as done | `task-cli mark-done 1`
| `list`  | Listing all tasks | `task-cli list`
| `list [done,todo,in-progress]`  | Listing tasks by status | `task-cli list todo`

## 🖥️ Installation

### 1. Clone the repository or download ZIP
```sh
// HTTPS
git clone https://github.com/nvalenne/task-tracker-cli.git 

// SSH
git clone git@github.com:nvalenne/task-tracker-cli.git
```
Then go to the repo folder.
### 2. Compile the project by using `g++` compiler :

```sh
g++ src/*.cpp -o task-cli
```
> [!IMPORTANT]
> You need to create the `/data` folder (where the json file will be stored)
> ```sh
> mkdir data
> ```
## ✨ Running the project

```sh
./task-cli [command] [...arguments]
```