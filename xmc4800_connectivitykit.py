from base import *
from devices import *

class XMC4800ConnectivityKit(Board):

    @staticmethod
    def match(dev):
        return dev["vid"]=="1366" and dev["pid"] in "0105"

    def _exe_jlink_script(self, jlink_script_content):
        jlink_script = fs.get_tempfile(jlink_script_content)
        res,out,err = proc.runcmd("jlinkexe", "-If", "swd", "-device", "XMC4800-2048", "-speed", "4000", "-autoconnect", "1", "-CommanderScript", jlink_script)
        fs.del_tempfile(jlink_script)
        return out

    def reset(self):
        self._exe_jlink_script('r\nexit')

    def burn(self,bin,outfn=None):
        vm_bin = fs.get_tempfile(bin)
        out = self._exe_jlink_script('loadbin "' + vm_bin + '", '+ self.to_dict()["vm_start"] +'\nr\nexit')
        fs.del_tempfile(vm_bin)

        for line in out.split('\n'):
            if 'O.K.' in line:
                break
        else:
            return False,out
        return True,out
