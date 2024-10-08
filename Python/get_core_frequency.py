import os
def get_core_frequency(core):
    """Get the frequency of a specific core from the system files."""
    try:
        # Path to the frequency file for the specific core
        freq_path = f'/sys/devices/system/cpu/cpu{core}/cpufreq/scaling_cur_freq'
        if os.path.exists(freq_path):
            # Read the frequency in kHz
            with open(freq_path, 'r') as f:
                frequency_khz = int(f.read().strip())
            # Convert to MHz
            return frequency_khz / 1000
        else:
            return 'Unknown'  # Frequency information not available
    except Exception as e:
        print(f"Error retrieving frequency for core {core}: {str(e)}")
        return 'Unknown'

if __name__ == '__main__':
  freq = get_core_frequency(0)
  print(freq)
