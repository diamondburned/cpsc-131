Hello Professor,

I've tried my best to adhere to the styling preference that you want us to use.

Well, I actually didn't want to try at all, because I'm normally used to
clang-format doing it for me. However, per my Homework 1, if I run that on any
file, it will screw up the auto-grader and give me an instant F.

I would strongly appreciate it if you could fix the auto-grader so that it does
not assume a re-indented TO-DO comment to be an invalid one, because
clang-format will touch them, and there's no way for me to fix that other than
to just not use clang-format at all.

I've had to mutilate a lot of my environment's configuration files already, like
adding an edge case into my init.vim specifically for C++ files to be indented
in certain ways.

Currently, both the supplemented clang-format and clang-tidy configuration files
that you gave us at the start of the semester yield unacceptable results:

	- clang-tidy flags existing code as having warnings, which while they're
	  valid, they're not my fault.
	- clang-format messes up TO-DO comments as described above.

If there's no way to modify the auto-grader to be more lenient on the formatting
(which I understand), then I think we shouldn't just pretend like there is a
clang-format standard file that anyone can use, because it clearly doesn't work.

Thank you for your time, and thank you for reading this.
