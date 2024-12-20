# -- CS-210 Programming Languages (C++) --



# Summarize the project and what problem it was solving.

The Corner Grocer project was developed to analyze and track the frequency of items purchased in a day from a text-based input file. The program provides users with various functionalities, including searching for an item’s frequency, displaying all item frequencies, visualizing the data in a histogram format, and saving frequency data to a backup file. This system addresses the problem of manually analyzing item purchases by automating data parsing, frequency tracking, and visualization, making it easier for store managers to identify trends and inventory needs.





# What did you do particularly well?

The modular and object-oriented design of the program is a notable achievement. Encapsulating functionality within the 'ItemTracker' class improved readability, maintainability, and reusability. Implementing robust error handling, such as displaying the current working directory for troubleshooting file issues, added a professional touch to the program. The histogram visualization and menu-driven interface were also well-executed, ensuring user-friendliness.





# Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?

The code could be enhanced by incorporating the following improvements:
        File Path Flexibility - Allow users to input the file path dynamically, making the program adaptable to different environments.
        Input Validation - Implement stricter checks for user input in the menu and during item searches to prevent errors or unexpected behavior.
        Thread Safety - Introduce thread-safe mechanisms for data handling if the program is expanded for concurrent user interactions.
        Efficiency - Optimize map operations by pre-sorting data for faster queries, especially for larger input files.





# Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?

One of the most challenging aspects was retrieving and displaying the current working directory using the Windows API (GetCurrentDirectoryW). The initial challenge stemmed from converting 'char*' to 'LPWSTR' to meet the API’s parameter requirements. This was resolved by using a 'wchar_t' buffer and correctly managing the character encoding. Online resources such as Microsoft Developer Network documentation and community forums were instrumental in overcoming this challenge. 
Key resources included:
        Microsoft Developer Network (MSDN) - For API documentation and examples.
        Stack Overflow - For troubleshooting and best practices.
        IDE Debugging Tools - Visual Studio’s debugger helped trace and resolve logic and runtime errors.





# What skills from this project will be particularly transferable to other projects or course work?

File I/O Handling - Skills in reading and writing files efficiently can be applied to other data-driven projects.
Data Structures - Experience with maps for storing key-value pairs will be useful in scenarios like caching and lookups.
Error Handling - Developing robust feedback mechanisms to assist users and troubleshoot problems is a critical skill for scalable applications.
API Integration - Familiarity with Windows API functions can support future system-level programming needs.





# How did you make this program maintainable, readable, and adaptable?

The program’s maintainability stems from its modular design, with all core functionality encapsulated in the ItemTracker class. Consistent naming conventions and inline comments enhance readability. Adaptability is ensured by designing the menu-driven interface and histogram visualization, which can be extended with minimal changes. The separation of concerns—data handling, file I/O, and user interaction ensures that future developers can modify or expand the program without disrupting existing functionality.
