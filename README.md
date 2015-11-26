# todos

*Simple-but-clever task management application!*

### DevTeam

- Dmytro Yurchenko
- Sergiy Shtelmakh  

### Brief description

The `todos` application is intended to help user in organizing his time. It is something like "to do list" application.

The main entity of the application is task. **Task** consists of a *title*, *priority*, *due date*, *commentary*, *reminder date* and *status* (completed or not). User can create, modify and remove tasks and organize them into categories. **Category** is a *named* set of tasks. Categories can be created, modified and removed. It is possible to move tasks from one category to another.

User can sort tasks by due date, priority and title criterias, using single or multiple criterias. Tasks can be filtered by category and due date.

Task's commentary is a list of records. Every record in commentary is one of the next: link, image, sound, text, attached document.

`todos` provides integration with Google API, so new tasks can be imported from Google Calendar.

The application has login and sign up screens, so different users can login from the same device. All information is stored separately for different users, so no one sees tasks of other.
