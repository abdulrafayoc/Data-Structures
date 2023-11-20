# Critical Path Method Program in C++

This program implements the Critical Path Method (CPM) in C++. It uses a variety of functions and classes to calculate and display the critical path, task dependencies, and completion times for a set of tasks.


## Classes

This program uses a variety of classes to represent tasks, resources, and skills.

## Class: Skill

The `Skill` class represents a skill that a resource can have.

### Private Members:

- `title`: The title of the skill.
- `id`: The unique identifier for the skill.
- `id_generator`: A static member used to generate unique IDs for each skill.
- `proficiency`: The proficiency level of the skill, represented as a decimal from 0 to 1.

## Class: Task

The `Task` class represents a task in the project.

### Private Members:

- `title`: The title of the task.
- `id`: The unique identifier for the task.
- `duration`: The duration of the task, in days.
- `ES`, `EF`, `LS`, `LF`: Early start, early finish, late start, late finish times for the task.
- `slack`: The slack time for the task, calculated as LS - ES.
- `skill_id`: The ID of the required skill for the task.
- `nexts`: A linked list storing IDs of next tasks.
- `prevs`: A linked list storing IDs of previous tasks.
- `id_generator`: A static member used to generate unique IDs for each task.

## Class: Resource

The `Resource` class represents a resource that can be assigned to a task.

### Private Members:

- `title`: The title of the resource.
- `id`: The unique identifier for the resource.
- `id_generator`: A static member used to generate unique IDs for each resource.
- `skill_id`: The ID of the skill that the resource has.
- `availability`: A boolean indicating whether the resource is available.


## Generic Classes

- `LinkedList<T>`: A generic linked list class that can hold any type of data.
- `Node<T>`: A generic node class that can hold any type of data.


## Functions

- `calculate_late_finish(LinkedList<Task> & tasks)`: Calculates the late finish time for each task.
- `completion_time_wrt_resources(LinkedList<Task>& tasks, LinkedList<Resource>& resources, LinkedList<Skill>& skills)`: Calculates the completion time of tasks with respect to available resources and skills.
- `display_basic_schedule(LinkedList<Task>& tasks)`: Displays the basic schedule of tasks.
- `display_menu(LinkedList<Task> & tasks, LinkedList<Resource>& resources, LinkedList<Skill>& skills)`: Displays the main menu for user interaction.
- `display_tasks_dependencies (LinkedList<Task>& tasks)`: Displays the dependencies between tasks.
- `edit_task(LinkedList<Task>& list)`: Allows the user to edit a task.
- `find_resource(LinkedList<Resource>& resources, int skill_id)`: Finds a resource based on a skill ID.
- `get_completion_time(LinkedList<Task>& tasks)`: Gets the completion time for all tasks.
- `load_predefined_data(LinkedList<Task>& tasks, LinkedList<Resource>& resources, LinkedList<Skill>& skills)`: Loads predefined data into the program.
- `menu(LinkedList<Task>& tasks, LinkedList<Resource>& resources, LinkedList<Skill>& skills)`: Handles user interaction with the menu.
- `print_critical_path(LinkedList<Task>& tasks)`: Prints the critical path of tasks.
- `sort_tasks(LinkedList<Task>& Tasks)`: Sorts tasks based on EF.
- `sort_tasks_slack(LinkedList<Task>& Tasks)`: Sorts tasks based on their slack time.
- `main()`: The main function of the program.

Please refer to the source code for more details on how these functions and classes are implemented and used. Happy coding! 🚀