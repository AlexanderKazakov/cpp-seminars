#!/usr/bin/env python3

import sys

class ErrorBase(Exception):
    pass

class ErrorDerived(ErrorBase):
    pass

for err in [Exception, ErrorBase, ErrorDerived]:
    try:
        raise(err)
    except ErrorDerived as e:
        print('ErrorDerived occurred')
    except ErrorBase as e:
        print('ErrorBase occurred')
    except Exception:
        print('Exception occured')

