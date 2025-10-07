#!/usr/bin/python3
import os

task_descriptions_file = open('tasks6.txt')
task_descriptions = ''.join(task_descriptions_file.readlines())
tasks = task_descriptions.split('-----\n')

for task in tasks:
    print(task.split('\n')[0], 'parsing...')
    task_id, title = task.split('\n')[0].split(': ')
    statement = task[task.find('\n\n') + 2:task.find('Ввод') - 1].split('\n')
    examples_text = task[task.find('Ввод') + len('Ввод') + 1:]
    examples = [tuple(example.split('Вывод\n')) for example in examples_text.split('Ввод\n')]
    out_text = """<?xml version="1.0" encoding="utf-8" ?>
    <problem
       package = "ru.ejudge.sample_contest"
       id = \"""" + task_id + """\"
       type = "standard">
      <statement language="ru_RU">
        <title> """ + title + """ </title>
        <description>""" + \
        ''.join(['<p>' + line + '</p>' for line in statement]) + """
        </description>
      </statement>
      <examples>
        """ + ''.join(["""<example>
          <input>""" + example_input + """</input>
          <output>""" + example_output + """</output>
        </example>""" for (example_input, example_output) in examples]) + """
      </examples>
    </problem>"""

    try:
        os.mkdir(task_id)
    except OSError:
        print('Directory', task_id, 'is already created')
        pass
    out_file = open(task_id + '/statement.xml', 'w')
    out_file.write(out_text)
    out_file.close()
