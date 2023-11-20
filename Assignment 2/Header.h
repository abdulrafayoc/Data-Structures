#pragma once

#include <iostream>
#include <cassert>
#include <string>
#include "Header1.h"
using namespace std;

class Task {
private:
	string title;
	int id;
	int duration; // in days
	int ES, EF, LS, LF; // early start, early finish, late start, late finish
	int slack; // LS - ES
	int skill_id;
	intLinkedList nexts; // store ids of next tasks
	intLinkedList prevs; // store ids of previous tasks
	// id generator 
	static int id_generator;
	// 11 data members
public:
	Task() {
		title = "";
		id = id;
		duration = 0;
		ES = 0;
		EF = 0;
		LS = 0;
		LF = 0;
		skill_id = 0;
		slack = 0;
	}
	Task(string title, int duration, int skill_id) {
		this->title = title;
		this->id = id_generator++;
		this->duration = duration;
		this->ES = 0;
		this->EF = 0;
		this->LS = 0;
		this->LF = 0;
		this->skill_id = skill_id;
		slack = 0;
	}
	Task(string title, int duration, int ES, int EF, int LS, int LF, int skill_id) {
		this->title = title;
		this->id = id_generator++;
		this->duration = duration;
		this->ES = ES;
		this->EF = EF;
		this->LS = LS;
		this->LF = LF;
		this->skill_id = skill_id;
		slack = LF - EF;
	}
	// == operator overloading
	bool operator==(Task& task) {
		if (this->id == task.id) {
			return true;
		}
		return false;
	}
	/*Task(Task& task) {
		this->title = task.title;
		this->id = task.id;
		this->duration = task.duration;
		this->ES = task.ES;
		this->EF = task.EF;
		this->LS = task.LS;
		this->LF = task.LF;
		this->skill_id = task.skill_id;
		slack = task.slack;
	}*/
	void set_title(string title) {
		this->title = title;
	}
	/*void set_id(int id) {
		this->id = id;
	}*/
	void set_duration(int duration) {
		this->duration = duration;
	}
	void set_ES(int ES) { // this also updates EF
		this->ES = ES;
		EF = ES + duration;
	}
	void set_EF(int EF) {
		this->EF = EF;
	}
	void set_LS(int LS) {
		this->LS = LS;
	}
	void set_LF(int LF) { // this also updates LS
		this->LF = LF;
		LS = LF - duration;
		slack = LF - EF;
	}
	void set_slack() {
		this->slack = LS - ES;
	}
	void set_skill_id(int skill_id) {
		this->skill_id = skill_id;
	}
	string get_title() {
		return title;
	}
	int get_id() {
		return id;
	}
	int get_duration() {
		return duration;
	}
	int get_ES() {
		return ES;
	}
	int get_EF() {
		return EF;
	}
	int get_LS() {
		return LS;
	}
	int get_LF() {
		return LF;
	}
	int get_slack() {
		return slack;
	}
	int get_skill_id() {
		return skill_id;
	}
	void print() {
		//cout << "Task ID: " << id << endl;
		//cout << "Duration: " << duration << endl;
		//cout << "Early Start: " << ES << endl;
		//cout << "Early Finish: " << EF << endl;
		//cout << "Late Start: " << LS << endl;
		//cout << "Late Finish: " << LF << endl;
		//cout << "Slack: " << slack << endl;
		//cout << "Next Task ID: " << next->get_id() << endl;
		//cout << "Skill ID: " << skill_id << endl;

		cout << "Task Title: " << title << endl;
		cout << " _____________ " << endl;
		cout << " | " << ES << " | " << duration << " | " << EF << " | " << endl;
		cout << " |   ID: " << id << "   | -->  Next Tasks IDs: "; for (int i = 0; i < nexts.get_size(); i++) { cout << nexts.get(i) << " "; } cout << endl;
		cout << " | " << LS << " | " << slack << " | " << LF << " | " << endl;
		cout << " ------------- " << endl;
		cout << "Skill ID: " << skill_id << endl;

		cout <<	"Next Tasks IDs: ";
		for (int i = 0; i < nexts.get_size(); i++) {
			cout << nexts.get(i) << " ";
		}
		cout << endl;
		cout << "Prev Tasks IDs: ";
		for (int i = 0; i < prevs.get_size(); i++) {
			cout << prevs.get(i) << " "; 
		} 
		cout << endl;


	}
	void add_next(LinkedList<Task>& tasks, int id) {
		// check if already exists then add
		/*if (!nexts.if_exist(task->get_id())) {
			nexts.add(task);
		}

		if (!task->get_prevs().if_exist(this->id)) {
			task->get_nexts().add(this);
		}*/
		if (!nexts.if_exist(id)) {
			nexts.add(id);
		}
		if (!tasks.find(id)->get_prevs()->if_exist(this->id)) {
			tasks.find(id)->get_prevs()->add(this->id);
		}
	}
	void add_prev(LinkedList<Task>& tasks, int id) {
		if (!prevs.if_exist(id)) {
			prevs.add(id);
			cout << "prevs size: " << prevs.get_size() << endl;
			cout << "Task ID:" << id << " added to prevs of task ID: " << this->id << endl;

		}
		if (!tasks.find(id)->get_nexts()->if_exist(this->id)) {
			tasks.find(id)->get_nexts()->add(this->id);
			cout << "nexts size: " << tasks.find(id)->get_nexts()->get_size() << endl;
		}
	}
	intLinkedList* get_nexts() {
		return &nexts;
	}
	intLinkedList* get_prevs() {
		return &prevs;
	}
};
int Task::id_generator = 1;

class Project {
private:
	string title;
	LinkedList<Task> tasks; // composition of all to tasks
	int num_tasks;
public:
	Project() {
		title = "";
		num_tasks = 0;
	}
	Project(string t, LinkedList<Task> &tasks) {
		this->title = t;
		this->tasks = tasks;
	}
	void print() {
		cout << "Tasks: " << endl;
		tasks.print();
	}

};

class Skill {
private:
	string title;
	int id;
	static int id_generator;
	float proficiency; // 0 low & 1 high // from 0.00 to 1.00
public:
	Skill() {
		title = "";
		id = 0;
		proficiency = 0;
	}
	Skill(string title, float proficiency) {
		this->title = title;
		this->id = id_generator++;
		this->proficiency = proficiency;
	}
	bool operator==(Skill& skill) {
		if (this->id == skill.id) {
			return true;
		}
		return false;
	}
	void set_title(string title) {
		this->title = title;
	}
	void set_proficiency(float proficiency) {
		this->proficiency = proficiency;
	}
	string get_title() {
		return title;
	}
	int get_id() {
		return id;
	}
	float get_proficiency() {
		return proficiency;
	}
	void print() {
		cout << "Skill Title: " << title << endl;
		cout << "Skill ID: " << id << endl;
		cout << "Proficiency: " << proficiency << endl;

	}
};
int Skill::id_generator = 1;

class Resource {
private:
	string title;
	int id;
	static int id_generator;
	int skill_id;
	bool availability; // 0 not available & 1 available 
public:
	Resource() {
		title = "";
		id = id_generator++;
		skill_id = NULL;
		availability = 0;
	}
	Resource(string title, int skill_id, bool availability) {
		this->title = title;
		this->id = id_generator++;
		this->skill_id = skill_id;
		this->availability = availability;
	}
	bool operator==(Resource& resource) {
		if (this->id == resource.id) {
			return true;
		}
		return false;
	}
	void set_title(string title) {
		this->title = title;
	}
	void set_skill_id(int skill_id) {
		this->skill_id = skill_id;
	}
	void set_availability(bool availability) {
		this->availability = availability;
	}
	string get_title() {
		return title;
	}
	int get_id() {
		return id;
	}
	int get_skill_id() {
		return skill_id;
	}
	bool get_availability() {
		return availability;
	}
	void print() {
		cout << "Resource Title: " << title << endl;
		cout << "Resource ID: " << id << endl;
		cout << "Skill ID: " << skill_id << endl;
		cout << "Availability: " << availability << endl;
	}
};
int Resource::id_generator = 1;

