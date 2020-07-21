from xmc4eth.xmc4eth import xmc4eth as drv
import eth

def init():
    drv.init()
    return drv

def interface():
    return eth






