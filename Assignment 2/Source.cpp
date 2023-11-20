#include <iostream>
#include <cassert>
#include <string>
#include "Header.h"
#include "Header1.h"

using namespace std;
// Add tasks to the list
void add_task(LinkedList<Task>& list) {
	cout << "Enter title of the task: " << endl;
	string title;
	cin.ignore();
	getline(cin, title);
	cout << "Enter duration of the task: " << endl;
	int duration;
	cin >> duration;
	cout << "Enter skill id of the task: " << endl;
	int skill;
	cin >> skill;

	Task task(title, duration, skill);
	list.add(task);
}
// Add resourses to the list
void add_resourse(LinkedList<Resource>& list) {
	cout << "Enter title of the resourse: " << endl;
	string title;
	cin.ignore();
	getline(cin, title);
	cout << "Enter availability of the resourse: " << endl;
	int availability;
	cin >> availability;
	cout << "Enter skill id of the resourse: " << endl;
	int skill;
	cin >> skill;

	Resource resourse(title, skill, availability);
	list.add(resourse);
}
// Add skills to the list
void add_skill(LinkedList<Skill>& list) {
	cout << "Enter title of the skill: " << endl;
	string title;
	cin.ignore();
	getline(cin, title);
	cout << "Enter proficiency of the skill: " << endl;
	float proficiency;
	cin >> proficiency;
	Skill skill(title, proficiency);
	list.add(skill);
}
// Edit task's title duration and skill needed 
void edit_task(LinkedList<Task>& list) {
	list.print();
	cout << "Enter id of the task: " << endl;
	int id;
	cin >> id;
	if (list.find(id)->get_id() != 0) {
		char choice;
		cout << "Do you want to edit title? [Y/N] :" << endl;
		cin >> choice;
		if (choice == 'Y' || choice == 'y') {
			cout << "Enter new title of the task: " << endl;
			string title;
			cin.ignore();
			getline(cin, title);
			list.find(id)->set_title(title);
		}
		cout << "Do you want to edit duration? [Y/N] :" << endl;
		cin >> choice;
		if (choice == 'Y' || choice == 'y') {
			cout << "Enter new duration of the task: " << endl;
			int duration;
			cin >> duration;
			list.find(id)->set_duration(duration);
		}
		cout << "Do you want to edit skill? [Y/N] :" << endl;
		cin >> choice;
		if (choice == 'Y' || choice == 'y') {
			cout << "Enter new skill id of the task: " << endl;
			int skill;
			cin >> skill;
			list.find(id)->set_skill_id(skill);
		}

	}
	else {
		cout << "Task not found!" << endl;
	}
}
// Sort tasks by early finish
void sort_tasks(LinkedList<Task>& Tasks) { // by early finish

	Node<Task>* curr = Tasks.get_head();
	while (curr != nullptr) {
		Node<Task>* temp = curr->next;
		while (temp != nullptr) {
			if (curr->data.get_EF() > temp->data.get_EF()) {
				Task temp_task = curr->data;
				curr->data = temp->data;
				temp->data = temp_task;
			}
			temp = temp->next;
		}
		curr = curr->next;
	}

}
// Sort tasks by slack
void sort_tasks_slack(LinkedList<Task>& Tasks) {
	// by slack 

	Node<Task>* curr = Tasks.get_head();
	while (curr != nullptr) {
		Node<Task>* temp = curr->next;
		while (temp != nullptr) {
			if (curr->data.get_slack() > temp->data.get_slack()) {
				Task temp_task = curr->data;
				curr->data = temp->data;
				temp->data = temp_task;
			}
			temp = temp->next;
		}
		curr = curr->next;
	}
}
// Calculate early start by adding duration of previous tasks
void calculate_early_start(LinkedList<Task>& tasks) {
	sort_tasks(tasks); // sort the list before this func
	Node<Task>* curr = tasks.get_head();
	while (curr != nullptr) {
		if (curr->data.get_prevs()->get_size() == 0) {
			curr->data.set_ES(0);
		}
		else {
			int max = 0;
			for (int i = 0; i < curr->data.get_prevs()->get_size(); i++) {
				if (tasks.find(curr->data.get_prevs()->get(i))->get_EF() > max) {
					max = tasks.find(curr->data.get_prevs()->get(i))->get_EF();
				}
			}
			curr->data.set_ES(max);
		}
		curr = curr->next;
	}
}
// Calculate late finish by adding duration of next tasks
void calculate_late_finish(LinkedList<Task>& tasks) {
	//sort_tasks(tasks); // sort the list before this func
	Node<Task>* curr = tasks.get_tail();
	while (curr != nullptr) {
		if (curr->data.get_nexts()->get_size() == 0) {
			curr->data.set_LF(curr->data.get_EF());
		}
		else {
			int min = 99999999;
			for (int i = 0; i < curr->data.get_nexts()->get_size(); i++) {
				if (tasks.find(curr->data.get_nexts()->get(i))->get_LS() < min) {
					min = tasks.find(curr->data.get_nexts()->get(i))->get_LS();
				}
			}
			curr->data.set_LF(min);
		}
		curr = curr->prev;
	}
}
// Load predefined data 
void load_predefined_data(LinkedList<Task>& tasks, LinkedList<Resource>& resourses, LinkedList<Skill>& skills) {

	// Tasks
	// title , duration , skill_id
	Task task1("Vison and Scope", 2, 1);
	Task task2("Requirement Analysis", 3, 1);

	Task task3("System Design", 4, 2);
	Task task4("Database Design", 3, 2);
	Task task5("UI Design", 2, 3);
	Task task6("Coding", 4, 4);
	Task task7("Testing", 3, 5);
	Task task8("Deployment", 2, 6);
	Task task9("Maintenance", 1, 6);

	tasks.add(task2);
	tasks.add(task1);

	tasks.add(task3);
	tasks.add(task4);
	tasks.add(task5);
	tasks.add(task6);
	tasks.add(task7);
	tasks.add(task8);
	tasks.add(task9);
	//	 adding dependencies
	tasks.find(2)->add_prev(tasks, 1);
	tasks.find(3)->add_prev(tasks, 1);
	tasks.find(4)->add_prev(tasks, 2);
	tasks.find(5)->add_prev(tasks, 2);
	tasks.find(9)->add_prev(tasks, 4);
	tasks.find(6)->add_prev(tasks, 3);
	tasks.find(6)->add_prev(tasks, 4);
	tasks.find(7)->add_prev(tasks, 6);
	tasks.find(8)->add_prev(tasks, 5);
	tasks.find(8)->add_prev(tasks, 7);
	tasks.find(9)->add_prev(tasks, 8);


	// resourses
	// title , skill_id , availability
	Resource resourse1("Bussiness Analysts", 1, true);
	Resource resourse2("Project Managers", 1, true);
	Resource resourse3("Database Designers", 2, true);
	Resource resourse4("UI Designers", 3, true);
	Resource resourse5("Programmers", 4, true);
	Resource resourse6("Testers", 5, true);
	Resource resourse7("Deployment Team", 6, true);

	resourses.add(resourse1);
	resourses.add(resourse2);
	resourses.add(resourse3);
	resourses.add(resourse4);
	resourses.add(resourse5);
	resourses.add(resourse6);
	resourses.add(resourse7);


	//skills
	// title , proficiency
	Skill skill1("Bussiness Analysis", 0.6);
	Skill skill2("System Analysis", 0.7);
	Skill skill3("Database Design", 0.8);
	Skill skill4("UI Design", 0.4);
	Skill skill5("Programming", 0.9);
	Skill skill6("Testing", 0.8);
	Skill skill7("Deployment and Maintenance", 0.5);

	skills.add(skill1);
	skills.add(skill2);
	skills.add(skill3);
	skills.add(skill4);
	skills.add(skill5);
	skills.add(skill6);
	skills.add(skill7);



	cout << "Pre-defined data loaded successfully!" << endl;

}
// Print critical path based on slack time
void print_critical_path(LinkedList<Task>& tasks) {
	sort_tasks_slack(tasks);
	cout << "The critical path is: " << endl;
	Node<Task>* curr = tasks.get_head();
	while (curr->data.get_nexts()->get_size() != 0) {
		if (curr->data.get_slack() == 0) {
			cout << curr->data.get_title() << " -> ";
		}
		curr = curr->next;
	}
	cout << "END" << endl << endl;

	cout << "Task\tDr\tES\tEF\tLS\tLF\tSlack" << endl;
	curr = tasks.get_head();
	while (curr->data.get_nexts()->get_size() != 0) {
		if (curr->data.get_slack() == 0) {
			cout << curr->data.get_id() << "\t" << curr->data.get_duration() << "\t" << curr->data.get_ES() << "\t" << curr->data.get_EF() << "\t" << curr->data.get_LS() << "\t" << curr->data.get_LF() << "\t" << curr->data.get_slack() << endl;
		}
		curr = curr->next;
	}


}
// Get completion time of the project
int get_completion_time(LinkedList<Task>& tasks) {
	Node<Task>* curr = tasks.get_head();
	int max = 0;
	while (curr != nullptr) {
		if (curr->data.get_EF() > max) {
			max = curr->data.get_EF();
		}
		curr = curr->next;
	}
	return max;
}
// Display basic schedule of the project 
void display_basic_schedule(LinkedList<Task>& tasks) {
	sort_tasks(tasks);
	calculate_early_start(tasks);
	calculate_late_finish(tasks);
	cout << "The basic schedule is: " << endl;
	cout << "Task\tDr\tES\tEF\tLS\tLF\tSlack" << endl;
	Node<Task>* curr = tasks.get_head();
	while (curr != nullptr) {
		cout << curr->data.get_id() << "\t" << curr->data.get_duration() << "\t" << curr->data.get_ES() << "\t" << curr->data.get_EF() << "\t" << curr->data.get_LS() << "\t" << curr->data.get_LF() << "\t" << curr->data.get_slack() << endl;
		curr = curr->next;
	}
	cout << "Completion Time: " << get_completion_time(tasks) << endl;
}
// Find a resourse by skill id
Resource find_resourse(LinkedList<Resource>& resourses, int skill_id) {
	Node<Resource>* curr = resourses.get_head();
	while (curr != nullptr) {
		if (curr->data.get_skill_id() == skill_id) {
			return curr->data;
		}
		curr = curr->next;
	}

}
// Calculate completion time based on resourse availability and skill proficiency
int completion_time_wrt_resources(LinkedList<Task>& tasks, LinkedList<Resource>& resourses, LinkedList<Skill>& skills) {
	/*//Calculate the project's completion time
	//considering resource availability, 
	//allowing tasks to start based on resource availability.
	//Display the schedule as well.

	// for profeciency (from 0 to 1 in decimals) if a task duration is 4 and profeciency is .5 the task will take 8 to get completed
	//resourse allocation has following prorities
	// Task with lowest late start
	// else Task with lowest slack
	// else Task with lowest duration


	completionTimeWithResources
		Calculates the project's completion time considering resource availability
		Allows tasks to start based on resource availability.
		Resource priority and proper resource allocation
		Displays the schedule*/

	Node<Task>* curr = tasks.get_head();
	while (curr != nullptr) {
		if (curr->data.get_prevs()->get_size() == 0 && find_resourse(resourses, curr->data.get_skill_id()).get_availability() == true) {
			curr->data.set_ES(0);
			curr->data.set_EF(ceil(curr->data.get_duration() / skills.find(curr->data.get_skill_id())->get_proficiency()));
			find_resourse(resourses, curr->data.get_skill_id()).set_availability(false);
		}
		else {
			int max = 0;
			for (int i = 0; i < curr->data.get_prevs()->get_size(); i++) {
				if (tasks.find(curr->data.get_prevs()->get(i))->get_EF() > max) {
					max = tasks.find(curr->data.get_prevs()->get(i))->get_EF();
				}
			}
			curr->data.set_ES(max);
			curr->data.set_EF(curr->data.get_ES() + curr->data.get_duration() * skills.find(curr->data.get_skill_id())->get_proficiency());
			find_resourse(resourses, curr->data.get_skill_id()).set_availability(false);
		}
		curr = curr->next;
	}
	return get_completion_time(tasks);



}
// Add dependencies and predcesors to the tasks
void add_dependencies(LinkedList<Task>& list) {
	list.print();

	cout << "Enter id of the task of which you want to add dependencies: " << endl;
	int id;
	cin >> id;


	cout << "How many dependents (Next Tasks) does this task have? " << endl;
	int num_next;
	cin >> num_next;
	for (int i = 0; i < num_next; i++) {
		cout << "Enter id of the dependent of this task (The Next Task): " << endl;
		int next;
		cin >> next;
		list.find(id)->add_next(list, next);
	}
	//list.find(id)->add_next(&list.find(next));

	cout << "How many dependencies (Previous Tasks) does this task have? " << endl;
	int num_prev;
	cin >> num_prev;
	for (int i = 0; i < num_prev; i++) {
		cout << "Enter id of the dependency of this task (The Previous Task): " << endl;
		int prev;
		cin >> prev;
		list.find(id)->add_prev(list, prev);
	}
	//list.find(id)->add_prev(&list.find(prev));

}
// Display tasks dependencies
void display_tasks_dependencies(LinkedList<Task>& tasks) {
	cout << "The basic schedule is: " << endl;
	cout << "Task\tDur\tPredecesors ID" << endl;
	Node<Task>* curr = tasks.get_head();
	while (curr != nullptr) {
		cout << curr->data.get_id() << "\t" << curr->data.get_duration() << "\t"; for (int i = 0; i < curr->data.get_prevs()->get_size(); i++) { cout << curr->data.get_prevs()->get(i) << " "; } cout << endl;
		curr = curr->next;
	}

}
// menu of Display 
void display_menu(LinkedList<Task>& tasks, LinkedList<Resource>& resourses, LinkedList<Skill>& skills) {
	cout << endl;
	cout << "---------------------" << endl;
	cout << "Please choose an option: " << endl;

	cout << "1. Display Tasks dependecies" << endl;
	cout << "2. Display Tasks Basic Sechdule" << endl;
	cout << "3. Display Critical Path" << endl;
	cout << "4. Display Resources" << endl;
	cout << "5. Display Skills" << endl;

	int choice;
	cin >> choice;

	if (choice == 1) {
		display_tasks_dependencies(tasks);
	}
	else if (choice == 2) {
		display_basic_schedule(tasks);
	}
	else if (choice == 3) {
		print_critical_path(tasks);
	}
	else if (choice == 4) {
		resourses.print();
	}
	else if (choice == 5) {
		skills.print();
	}
	else {
		cout << "Invalid choice!" << endl;
	}


	//if (tasks.get_size() == 0) {
	//	cout << "There are no tasks yet!" << endl;
	//	return;
	//}
	//
	//
	//cout << "Tasks: " << endl;
	//tasks.print();
	//cout << "Resourses: " << endl;
	//resourses.print();
	//cout << "Skills: " << endl;
	//skills.print();
}
// Display menu
void menu(LinkedList<Task>& tasks, LinkedList<Resource>& resourses, LinkedList<Skill>& skills) {

	cout << endl;
	cout << "---------------------" << endl;
	cout << "Please choose an option: " << endl;

	cout << "1. Add a Resourse" << endl;
	cout << "2. Add a Task" << endl;
	cout << "3. Add a Skill" << endl;

	cout << "4. Add a Dependency of a Task" << endl;
	cout << "5. Calculate Early Start" << endl;
	cout << "6. Calculate Late Finish" << endl;

	cout << "7. Edit a Task's Detail" << endl;
	cout << "8. Find Critical Path" << endl;
	cout << "9. Calculate Completion Time with Resources" << endl;

	cout << "10. Display Tasks, Resources and Skills" << endl;
	cout << "11. Exit" << endl;
	cout << "12. Load Predefined Data" << endl;


	int choice= 0;
	cin >> choice;

	switch (choice)
	{
	case 1:
		add_resourse(resourses);
		break;
	case 2:
		add_task(tasks);
		break;
	case 3:
		add_skill(skills);
		break;
	case 4:
		add_dependencies(tasks);
		break;
	case 5:
		calculate_early_start(tasks);
		calculate_early_start(tasks);
		break;
	case 6:
		calculate_late_finish(tasks);
		calculate_late_finish(tasks);
		break;
	case 7:
		edit_task(tasks);
		break;
	case 8:
		print_critical_path(tasks);
		break;
	case 9:
		completion_time_wrt_resources(tasks, resourses, skills);
		break;
	case 10:
		display_menu(tasks, resourses, skills);
		break;
	case 11:
		exit(0);
		break;
	case 12:
		load_predefined_data(tasks, resourses, skills);

	default:
		break;
	}
}
// Main function
int main() {
	cout << "Hello from CPM program!" << endl;

	LinkedList<Task> tasks;
	LinkedList<Resource> resourses;
	LinkedList<Skill> skills;

	Project project("Software Development",tasks);

	while (1) {
		menu(tasks, resourses, skills);
	}

	return 0;
}