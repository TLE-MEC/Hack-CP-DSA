from collections import Counter


# Counter is similar to a frequency table
class Solution:
    def leastInterval(self, tasks: list, n: int) -> int:
        if n == 0:
            # no requirement for cooling, just do those jobs in original order
            return len(tasks)

        # key: task, value: occurrence of tasks
        task_occ_dict = Counter(tasks)

        # max occurrence among tasks
        max_occurrence = max(task_occ_dict.values())
        number_of_tasks_of_max_occ = sum(
            (1 for task, occ in task_occ_dict.items()
             if occ == max_occurrence))

        # Make (max_occ-1) groups, each groups size is (n+1) to meet the requirement of cooling
        # Fill each group with uniform iteration leaving as even as possible
        # At last, execute for the last time of max_occ jobs
        interval_for_schedule = (max_occurrence -
                                 1) * (n + 1) + number_of_tasks_of_max_occ

        # Minimal length is original length on best case.
        # Otherswise, it need some idle time intervals
        return max(len(tasks), interval_for_schedule)
