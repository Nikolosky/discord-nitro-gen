
#CHECKER FROM "https://github.com/webtr333"

import os
import requests
import threading
import sys
import random
from colorama import Fore, init;init(convert = True)
import time

def get_domain():
    """> Simply discords domain for nitro - you can also change the variable to https://discord.com/gifts/ or remove the http:// bit - up to your choosing """
    return f"https://discord.gift/"

def clear():
    """> Clears screen"""
    try:
        os.system("cls")
    except:
        pass

def pprint(text,color,spacing=0):
    """> This lets me print stuff nicely and if I choose to change the interface I won't need to edit lots of individual print statements"""
    spacestr = spacing * " "
    
    print(f"{color}[{spacestr}{Fore.WHITE}{text}{color}{spacestr}]{Fore.WHITE}")

def make_title(content):
    """> Titles the window"""
    os.system(f"title {content}")

rps = 0;status="Waiting";total_codes = 0
def per_second_check():
    global rps,status,total_codes
    """> Calculates actions a second"""
    while True:
        if status == "> Waiting for user":
            make_title(status)
        else:
            time.sleep(1)
            make_title(f"{rps} {status}, {total_codes} total")
            rps = 0

def write_code(nitro,file="codes.txt"):
    """> Used for writing down codes - can be on generation, success, retries, ratelimits etc"""
    f = open(file,"a")
    f.write(f"{nitro}\n")
    f.close()
    
def get_written_codes(file="codes.txt"):
    """> Used for reading the file and getting it into a list variable"""
    f = open(file)
    allcodes = f.readlines()
    codesall = []
    for code in allcodes:
        if "discord" in code:
            codesall.append(code.replace("\n",""))
            if len(codesall) % 100 == 0:
                pprint(f"{len(codesall)} nitros loaded.",Fore.CYAN,9)
                make_title(f"{len(codesall)} codes loaded")
    return codesall

enabled = False

def check_code(nitro):
    global rps,total_codes
    """> Uses discord API to check code"""
    just_code = nitro.split("/")[1]
    api_url = f"https://discord.com/api/v9/entitlements/gift-codes/{just_code}?with_application=true&with_subscription_plan=true"
    try:
        r = requests.get(f"{api_url}",timeout=30)
        total_codes += 1;rps+=1
        if r.status_code == 404:
            pprint(f"{nitro} > INVALID",Fore.RED)
        elif r.status_code == 429:
            pprint(f"{nitro} RATELIMITED",Fore.RED)
            write_code(nitro,"retry.txt")
        elif r.status_code == 200:
            pprint(f"{nitro} > VALID",Fore.GREEN)
            write_code(nitro,"valid.txt")
    except Exception as e:
        if random.randint(1,400) == 1:
            pprint(f"{nitro} > Timeout",Fore.RED)
        write_code(nitro,"retry.txt")       


def check():
    """> Checks nitro codes"""
    pprint("Max threads? (Recommended : 50)",Fore.GREEN)
    max_threads = input()
    try:
        max_threads = int(max_threads)
    except:
        max_threads = 50
    allcodes = get_written_codes()

    for nitro in allcodes:
        while threading.active_count() > max_threads:
            time.sleep(0.1)
        threading.Thread(target = check_code, args = (nitro,)).start()

def startprint():
    """> Specifies printing"""
    sys.stdout = sys.__stdout__

def main():
    """> Manages everything"""
    global status
    clear();startprint()
    threading.Thread(target = per_second_check).start()
    status = "checked this second"
    check()

main()
input()
#CHECKER FROM "https://github.com/webtr333"